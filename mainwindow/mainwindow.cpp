#include "mainwindow.h"
#include "connectionmanager.h"
#include "modelqmlcontext.h"
#include "quickwidgetproxy.h"
#include "osgearth.h"
#include "welcomemode.h"
#include "svgimageprovider.h"
#include "attitudestate1.h"
#include "uavobjectbrowserwidget.h"
#include "opmapgadgetwidget.h"
#include "uavobjectsplugin.h"
#include <iostream>
#include <QFileInfo>
#include <qstylefactory.h>
#include <QtCore/QDebug>
#include <QtCore/QFileInfo>
#include <QtCore/QSettings>
#include <QtCore/QTimer>
#include <QtCore/QtPlugin>
#include <QtCore/QUrl>

#include <QtWidgets/QApplication>
#include <QCloseEvent>
#include <QMenuBar>
#include <QMenu>
#include <QPixmap>
#include <QShortcut>
#include <QStatusBar>
#include <QWizard>
#include <QToolButton>
#include <QMessageBox>
#include <QDesktopServices>
#include <QElapsedTimer>
#include <QDir>
#include <QMimeData>
#include <QLabel>
#include <QHBoxLayout>
#include <QVBoxLayout>
#include <QThreadPool>

MainWindow *MainWindow::instance = 0;
QMutex MainWindow::smutex;

MainWindow::MainWindow() :
    QMainWindow()
{
  attitudeState1 = new AttitudeState1();
  setWindowTitle(QLatin1String("TestPilot") + " " + "1.0");
  qApp->setWindowIcon(QIcon(":/images/librepilot_logo_128.png"));
  qApp->setStyle(QStyleFactory::create("Fusion"));

  setDockNestingEnabled(true);

  setCorner(Qt::BottomLeftCorner, Qt::LeftDockWidgetArea);
  setCorner(Qt::BottomRightCorner, Qt::BottomDockWidgetArea);

  createActions();
  createMenus();
  UAVObjectsPlugin::initialize();

  tabWidget = new QTabWidget(this);
  tabWidget->setIconSize(QSize(24, 24));
  tabWidget->setTabPosition(QTabWidget::South);
  tabWidget->setMovable(false);
  tabWidget->setMinimumWidth(512);
  tabWidget->setElideMode(Qt::ElideRight);

  connectionManager = new ConnectionManager(this);
  tabWidget->setCornerWidget(connectionManager, Qt::TopRightCorner);
  // create welcome mode
  welcomeMode = new WelcomeMode();
  tabWidget->addTab(welcomeMode->widget(), welcomeMode->icon(), welcomeMode->name());

  // create pfd mode
  createPfdQmlWidget();
  tabWidget->addTab(pfdQmlWidget->widget(), welcomeMode->icon(), "Pfd");

  //create model mode
  OsgEarth::registerQmlTypes();
  createModelQmlWidget();
  tabWidget->addTab(modelQmlWidget->widget(), welcomeMode->icon(), "Model");

  //create uavobject widget
  uavObjectBrowserWidget = new UAVObjectBrowserWidget(this);
  tabWidget->addTab(uavObjectBrowserWidget, welcomeMode->icon(), "UAVObject");
  // create opmap widget
  opmapGadgetWidget = new OPMapGadgetWidget(this);
  tabWidget->addTab(opmapGadgetWidget, welcomeMode->icon(), "opmap");

  QPushButton *attitudeButton = new QPushButton("attitude", this);
  connect(attitudeButton, SIGNAL (released()), this, SLOT (handleButton()));
  pitchLabel = new QLabel();
  rollLabel = new QLabel();
  yawLabel = new QLabel();
  pitchLabel->setText("0");
  rollLabel->setText("0");
  yawLabel->setText("0");
  QHBoxLayout *hboxLayout = new QHBoxLayout();
  hboxLayout->addWidget(attitudeButton);
  hboxLayout->addWidget(pitchLabel);
  hboxLayout->addWidget(rollLabel);
  hboxLayout->addWidget(yawLabel);

  QVBoxLayout *vboxLayout = new QVBoxLayout();
  vboxLayout->addWidget(tabWidget);
  vboxLayout->addLayout(hboxLayout);
  QWidget *widget = new QWidget(this);
  widget->setLayout(vboxLayout);
  setCentralWidget(widget);
}

MainWindow::~MainWindow()
{
}

void MainWindow::VaryPitch::run() {
  for(int i = 0; i < 360; ++i) {
    qDebug() << "i: " << i;
    mainWindow->attitudeState1->setPitch(i);
    mainWindow->pitchLabel->setText(QString::number(i));
    QThread::msleep(100);
  }
}

void MainWindow::handleButton()
{
    qDebug() << "start handlebutton";
  QThreadPool *threadPool = QThreadPool::globalInstance();
  VaryPitch *varyPitch = new VaryPitch(this);
  varyPitch->setAutoDelete(true);
  threadPool->start(varyPitch);
}

void MainWindow::createPfdQmlWidget()
{
  QString fN("./share/qml/Pfd.qml");
  QFileInfo check_file(fN);
  if (check_file.isFile()) {
    qDebug() << fN << " is a file";
    fN = check_file.absoluteFilePath();
  } else {
    qDebug() << fN << " is not a file";
    return;
  }
  pfdQmlWidget = new QuickWidgetProxy();
  SvgImageProvider *svgProvider = new SvgImageProvider(fN);
  pfdQmlWidget->addImageProvider("svg", svgProvider);
  pfdQmlWidget->setEngineContextProperty("svgRenderer", svgProvider);
  pfdQmlWidget->setContextProperty("attitudeState", attitudeState1);

  QUrl url = QUrl::fromLocalFile(fN);
  pfdQmlWidget->setSource(url);
  pfdQmlWidget->setBaseUrl(url);
}

void MainWindow::createModelQmlWidget()
{
  modelQmlWidget = new QuickWidgetProxy();
  ModelQmlContext *modelQmlContext = new ModelQmlContext();

  QFileInfo check_file("./share/backgrounds/default_background.png");
  //modelQmlContext->setBackgroundImageFile("D:/msys64/home/DELL/qt/build-testpilot-Desktop_Qt_MinGW_w64_64bit_MSYS2-Debug/app/share/backgrounds/default_background.png");
  modelQmlContext->setBackgroundImageFile(check_file.absoluteFilePath());
  check_file.setFile("./share/models/multi/test_quad/test_quad_x.3ds");
  // modelQmlContext->setModelFile("D:/msys64/home/DELL/qt/build-testpilot-Desktop_Qt_MinGW_w64_64bit_MSYS2-Debug/app/share/models/multi/test_quad/test_quad_x.3ds");
  modelQmlContext->setModelFile(check_file.absoluteFilePath());
  modelQmlWidget->setContextProperty("pfdContext", modelQmlContext);
  modelQmlWidget->setContextProperty("attitudeState", attitudeState1);
  // QString fN("./share/qml/Model.qml");
  check_file.setFile("./share/qml/Model.qml");
  if (check_file.isFile()) {
    qDebug() << " is a file";
  } else {
    qDebug() << " is not a file";
  }
  // fN = check_file.absoluteFilePath();
  QUrl url = QUrl::fromLocalFile(check_file.absoluteFilePath());
  modelQmlWidget->setSource(url);
  modelQmlWidget->setBaseUrl(url);
}

void MainWindow::createActions()
{
  // file menu's actions
  saveGcsDefaultSettingsAct = new QAction(tr("Save &GCS Default Settings"), this);
  saveGcsDefaultSettingsAct->setShortcut(tr("Ctrl+Shift+S"));
  connect(saveGcsDefaultSettingsAct, SIGNAL(triggered()), this, SLOT(saveGcsDefaultSettings()));
  exportUavSettingsAct = new QAction(tr("Export UAV Setting"), this);
  exportUavSettingsAct->setShortcut(tr("Ctrl+E"));
  connect(exportUavSettingsAct, SIGNAL(triggered()), this, SLOT(exportUavSettings()));
  importUavSettingsAct = new QAction(tr("Import UAV Setting"), this);
  importUavSettingsAct->setShortcut(tr("Ctrl+I"));
  connect(exportUavSettingsAct, SIGNAL(triggered()), this, SLOT(exportUavSettings()));
  gcsSettingImportExportAct = new QAction(tr("GCS Setting Import/Export..."), this);
  gcsSettingImportExportAct->setShortcut(tr("Ctrl+S"));
  connect(gcsSettingImportExportAct, SIGNAL(triggered()), this, SLOT(gcsSettingImportExport()));
  exitAct = new QAction(tr("Exit"), this);
  exitAct->setShortcut(tr("Ctrl+Q"));
  connect(exitAct, SIGNAL(triggered()), this, SLOT(exit()));

  // edit menu's actions
  undoAct = new QAction(tr("&Undo"), this);
  undoAct->setShortcut(tr("Ctrl+Z"));
  connect(undoAct, SIGNAL(triggered()), this, SLOT(undo()));
  redoAct = new QAction(tr("&Redo"), this);
  redoAct->setShortcut(tr("Ctrl+Y"));
  connect(redoAct, SIGNAL(triggered()), this, SLOT(redo()));
  cutAct = new QAction(tr("Cu&t"), this);
  cutAct->setShortcut(tr("Ctrl+X"));
  connect(cutAct, SIGNAL(triggered()), this, SLOT(cut()));
  copyAct = new QAction(tr("&Copy"), this);
  copyAct->setShortcut(tr("Ctrl+C"));
  connect(copyAct, SIGNAL(triggered()), this, SLOT(copy()));
  pasteAct = new QAction(tr("&Paste"), this);
  pasteAct->setShortcut(tr("Ctrl+V"));
  connect(pasteAct, SIGNAL(triggered()), this, SLOT(paste()));
  selectAllAct = new QAction(tr("&Select All"), this);
  selectAllAct->setShortcut(tr("Ctrl+A"));
  connect(selectAllAct, SIGNAL(triggered()), this, SLOT(selectAll()));

  // tools menu's actions
  optionsAct = new QAction(tr("&Options"), this);
  connect(optionsAct, SIGNAL(triggered()), this, SLOT(options()));
  manageFlightSideLogsAct = new QAction(tr("Manage flight side logs..."), this);
  manageFlightSideLogsAct->setShortcut(tr("Ctrl+F"));
  connect(manageFlightSideLogsAct, SIGNAL(triggered()), this, SLOT(manageFlightSideLogs()));
  startLoggingAct = new QAction(tr("Starting logging..."), this);
  startLoggingAct->setShortcut(tr("Ctrl+L"));
  connect(startLoggingAct, SIGNAL(triggered()), this, SLOT(startLogging()));
  vehicleSetupWizardAct = new QAction(tr("Vehicle Setup Wizard"), this);
  connect(vehicleSetupWizardAct, SIGNAL(triggered()), this, SLOT(vehicleSetupWizard()));
  exportImportVehicleTemplateAct = new QAction(tr("Export/Import Vehicle Template"), this);
  connect(exportImportVehicleTemplateAct, SIGNAL(triggered()), this, SLOT(exportImportVehicleTemplate()));
  transmitterSetupWizrdAct = new QAction(tr("Transmitter Setup Wizard"), this);
  transmitterSetupWizrdAct->setShortcut(tr("Ctrl+T"));
  connect(transmitterSetupWizrdAct, SIGNAL(triggered()), this, SLOT(transmitterSetupWizrd()));

  // window menu's actions
  fullScreenAct = new QAction(tr("Full Screen"), this);
  fullScreenAct->setShortcut(tr("Ctrl+Shift+F11"));
  connect(fullScreenAct, SIGNAL(triggered()), this, SLOT(fullScreen()));
  editGadgetsModeAct = new QAction(tr("Edit Gadgets Mode"), this);
  editGadgetsModeAct->setShortcut(tr("Ctrl+Shift+F10"));
  connect(editGadgetsModeAct, SIGNAL(triggered()), this, SLOT(editGadgetsMode()));
  splitAct = new QAction(tr("Split"), this);
  splitAct->setShortcut(tr("Ctrl+Shift+Down"));
  connect(splitAct, SIGNAL(triggered()), this, SLOT(split()));
  splitSideBySideAct = new QAction(tr("Split Side by Side"), this);
  splitSideBySideAct->setShortcut(tr("Ctrl+SHIFT+Right"));
  connect(splitSideBySideAct, SIGNAL(triggered()), this, SLOT(splitSideBySide()));
  closeCurrentViewAct = new QAction(tr("Close Current View"), this);
  closeCurrentViewAct->setShortcut(tr("Ctrl+Shift+C"));
  connect(closeCurrentViewAct, SIGNAL(triggered()), this, SLOT(closeCurrentView()));
  closeAllOtherViewsAct = new QAction(tr("Close All Other Views"), this);
  closeAllOtherViewsAct->setShortcut(tr("Ctrl+Shift+A"));
  connect(closeAllOtherViewsAct, SIGNAL(triggered()), this, SLOT(closeAllOtherViews()));
  gotoNextViewAct = new QAction(tr("Goto Next View"), this);
  gotoNextViewAct->setShortcut(tr("Ctrl+Shift+N"));
  connect(gotoNextViewAct, SIGNAL(triggered()), this, SLOT(gotoNextView()));

  // help menu's actions
  helpAct = new QAction(tr("&Help"), this);
  connect(helpAct, SIGNAL(triggered()), this, SLOT(help()));
  exportUAVDataAct = new QAction(tr("Export UAV Data..."), this);
  connect(exportUAVDataAct, SIGNAL(triggered()), this, SLOT(exportUAVData()));
  aboutPluginsAct = new QAction(tr("About &Plugins"), this);
  connect(aboutPluginsAct, SIGNAL(triggered()), this, SLOT(aboutPlugins()));
  aboutTestPilotAct = new QAction(tr("About &TestPilot..."), this);
  connect(aboutTestPilotAct, SIGNAL(triggered()), this, SLOT(aboutTestPilot()));
}

void MainWindow::createMenus()
{
  // file menu
  fileMenu = menuBar()->addMenu(tr("&File"));
  fileMenu->addAction(saveGcsDefaultSettingsAct);
  fileMenu->addAction(exportUavSettingsAct);
  fileMenu->addAction(importUavSettingsAct);
  fileMenu->addAction(gcsSettingImportExportAct);
  fileMenu->addSeparator();
  fileMenu->addAction(exitAct);
  // edit menu
  editMenu = menuBar()->addMenu(tr("&Edit"));
  editMenu->addAction(undoAct);
  editMenu->addAction(redoAct);
  editMenu->addSeparator();
  editMenu->addAction(cutAct);
  editMenu->addAction(copyAct);
  editMenu->addAction(pasteAct);
  editMenu->addSeparator();
  editMenu->addAction(selectAllAct);
  // tools menu
  toolsMenu = menuBar()->addMenu(tr("&Tools"));
  toolsMenu->addAction(optionsAct);
  toolsMenu->addSeparator();
  toolsMenu->addAction(manageFlightSideLogsAct);
  toolsMenu->addSeparator();
  toolsMenu->addAction(startLoggingAct);
  toolsMenu->addSeparator();
  toolsMenu->addAction(vehicleSetupWizardAct);
  toolsMenu->addSeparator();
  toolsMenu->addAction(exportImportVehicleTemplateAct);
  toolsMenu->addAction(transmitterSetupWizrdAct);
  // window menu
  windowMenu = menuBar()->addMenu(tr("&Window"));
  windowMenu->addAction(fullScreenAct);
  windowMenu->addSeparator();
  windowMenu->addAction(editGadgetsModeAct);
  windowMenu->addSeparator();
  windowMenu->addAction(splitAct);
  windowMenu->addAction(splitSideBySideAct);
  windowMenu->addAction(closeCurrentViewAct);
  windowMenu->addAction(closeAllOtherViewsAct);
  windowMenu->addAction(gotoNextViewAct);
  windowMenu->addSeparator();
  // help
  helpMenu = menuBar()->addMenu(tr("&Help"));
  helpMenu->addAction(helpAct);
  helpMenu->addAction(exportUAVDataAct);
  helpMenu->addSeparator();
  helpMenu->addAction(aboutPluginsAct);
  helpMenu->addAction(aboutTestPilotAct);
}
