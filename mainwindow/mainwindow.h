#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QMap>
#include <QSettings>
#include <QMainWindow>
#include <QTabWidget>
#include <QDebug>
#include <QRunnable>
#include <QMutex>
#include <QMutexLocker>

class ConnectionManager;
class WelcomeMode;
class QuickWidgetProxy;
class AttitudeState1;
class UAVObjectBrowserWidget;
class OPMapGadgetWidget;
class QLabel;

class MainWindow : public QMainWindow {
  Q_OBJECT

public:
  static MainWindow & getInstance() {
    if (instance == NULL) {
      QMutexLocker locker(&smutex);
      if (instance == NULL){
	instance = new MainWindow();      
      }
    }
    return *instance;
  }
private:
  MainWindow();
  ~MainWindow();
public:
  class VaryPitch : public QRunnable {
  public:
    VaryPitch (MainWindow *w) {
      mainWindow = w;
    }
    void run();
  private:
    MainWindow *mainWindow;
  };
 private:
  void createPfdQmlWidget();
  void createModelQmlWidget();
 private slots:
   void handleButton();
   // actions
    void saveGcsDefaultSettings()
    {
      qDebug() << "saveGcsDefaultSettings";
    }
    void exportUavSettings()
    {
      qDebug() << "exportUavSettings";
    }
    void importUavSettings()
    {
      qDebug() << "importUavSettings" ;
    }
    void gcsSettingImportExport()
    {
      qDebug() << "gcsSettingImportExport";
    }
    void exit()
    {
      qDebug() << "exit";
    }

    void undo()
    {
      qDebug() << "undo";
    }
    void redo()
    {
      qDebug() << "redo";
    }
    void cut()
    {
      qDebug() << "cut";
    }
    void copy()
    {
      qDebug() << "copy";
    }
    void paste()
    {
      qDebug() << "paste";
    }
    void selectAll()
    {
      qDebug() << "selectAll";
    }

    void options()
    {
      qDebug() << "options";
    }
    void manageFlightSideLogs()
    {
      qDebug() << "manageFlightSideLogs";
    }
    void startLogging()
    {
      qDebug() << "startLogging";
    }
    void vehicleSetupWizard()
    {
      qDebug() << "vehicleSetupWizard";
    }
    void exportImportVehicleTemplate()
    {
      qDebug() << "exportImportVehicleTemplate";
    }
    void transmitterSetupWizrd()
    {
      qDebug() << "transmitterSetupWizrd";
    }

    void fullScreen()
    {
      qDebug() << "fullScreen";
    }
    void editGadgetsMode()
    {
      qDebug() << "editGadgetsMode";
    }
    void split()
    {
      qDebug() << "split";
    }
    void splitSideBySide()
    {
      qDebug() << "splitSideBySide";
    }
    void closeCurrentView()
      
    {
      qDebug() << "closeCurrentView";
    }
    void closeAllOtherViews()
    {
      qDebug() << "closeAllOtherViews";
    }
    void gotoNextView()
    {
      qDebug() << "gotoNextView";
    }

    void help()
    {
      qDebug() << "help";
    }
    void exportUAVData()
    {
      qDebug() << "exportUAVData";
    }
    void aboutPlugins()
    {
      qDebug() << "aboutPlugins";
    }
    void aboutTestPilot()
    {
      qDebug() << "aboutTestPilot";
    }

 private:
    void createMenus();
    void createActions();

    // menus
    QMenu *fileMenu;
    QMenu *editMenu;
    QMenu *toolsMenu;
    QMenu *windowMenu;
    QMenu *helpMenu;
    
    // actions
    QAction *saveGcsDefaultSettingsAct;
    QAction *exportUavSettingsAct;
    QAction *importUavSettingsAct;
    QAction *gcsSettingImportExportAct;
    QAction *exitAct;

    QAction *undoAct;
    QAction *redoAct;
    QAction *cutAct;
    QAction *copyAct;
    QAction *pasteAct;
    QAction *selectAllAct;

    QAction *optionsAct;
    QAction *manageFlightSideLogsAct;
    QAction *startLoggingAct;
    QAction *vehicleSetupWizardAct;
    QAction *exportImportVehicleTemplateAct;
    QAction *transmitterSetupWizrdAct;

    QAction *fullScreenAct;
    QAction *editGadgetsModeAct;
    QAction *splitAct;
    QAction *splitSideBySideAct;
    QAction *closeCurrentViewAct;
    QAction *closeAllOtherViewsAct;
    QAction *gotoNextViewAct;

    QAction *helpAct;
    QAction *exportUAVDataAct;
    QAction *aboutPluginsAct;
    QAction *aboutTestPilotAct;
    
    ConnectionManager *connectionManager;
    QTabWidget *tabWidget;
    WelcomeMode *welcomeMode;
    QuickWidgetProxy *pfdQmlWidget;
    QuickWidgetProxy *modelQmlWidget;
    AttitudeState1 *attitudeState1;
    UAVObjectBrowserWidget *uavObjectBrowserWidget;
    OPMapGadgetWidget *opmapGadgetWidget;
    QLabel *pitchLabel;
    QLabel *rollLabel;
    QLabel *yawLabel;
  static MainWindow *instance;
  static QMutex smutex;
};

#endif // MAINWINDOW_H
// Local Variables:
// mode: C++
// End:
