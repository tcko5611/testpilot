#ifndef MAINWINDOW_H
#define MAINWINDOW_H

#include <QtCore/QMap>
#include <QSettings>
#include <QMainWindow>
#include <QTabWidget>
#include <QDebug>
#include <QRunnable>

class QSettings;
class QShortcut;
class QToolButton;
class ConnectionManager;
class WelcomeMode;
class QuickWidgetProxy;
class AttitudeState1;
class QLabel;
class MainWindow : public QMainWindow {
  Q_OBJECT

 public:
  MainWindow();
  ~MainWindow();
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
    QLabel *pitchLabel;
    QLabel *rollLabel;
    QLabel *yawLabel;
};

#endif // MAINWINDOW_H
