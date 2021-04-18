#include "testwindow.h"
#include "./ui_testwindow.h"

TestWindow::TestWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::TestWindow)
{
    ui->setupUi(this);

    connect(ui->actionOpen, &QAction::triggered, this, &TestWindow::openClicked);
    connect(ui->actionPlay, &QAction::triggered, this, &TestWindow::playClicked);
    connect(ui->actionClose, &QAction::triggered, this, &TestWindow::closeClicked);
    connect(ui->actionReceiveList, &QAction::triggered,
            this, &TestWindow::receiveListClicked);
    connect(ui->actionResetReceiveList, &QAction::triggered,
            this, &TestWindow::resetReceiveListClicked);
    connect(ui->actionGetInformation, &QAction::triggered,
            this, &TestWindow::getInformationClicked);
}

TestWindow::~TestWindow()
{
    if(pluginloader != nullptr){

        ExtraPluginInterface *ext = qobject_cast<ExtraPluginInterface *>(plugininstance);
        if(ext->getInformation()->hassettingwidget){
            disconnect(ext->getInformation()->settingwidget,
                       &PluginWidget::sendList,
                       ui->pluginTableWidget,
                       &DummyTable::insertSettingUpdate);
        }

        pluginloader->unload();
        plugininstance = nullptr;
        delete pluginloader;
    }

    delete ui;
}

void TestWindow::preloadPlugin(QStringList args)
{
    auto showMessage = [](){
        QMessageBox msgBox;
        msgBox.setIcon(QMessageBox::Warning);
        msgBox.setText(tr("Failed to load the plugin specified in the argument.\n"
                          "Usage: testwindow.exe <input file path>"));
        msgBox.exec();
    };

    if(args.count() > 2){
        showMessage();
    }

    if(args.count() == 2
        && !loadPluginInstance(args.at(1))){
        showMessage();
    }
}

void TestWindow::openClicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);

#ifdef Q_OS_WIN
    QString extension = "(*.dll)";
#else
    QString extension = "(*.*)";
#endif
    QString file
        = dialog.getOpenFileName(this,
                                 tr("Open Plugin"),
                                 QDir::currentPath(),
                                 tr("Plugin ") + extension );

    loadPluginInstance(file);
}

void TestWindow::playClicked()
{
    if(pluginloader == nullptr) return;

    ExtraPluginInterface *ext
        = qobject_cast<ExtraPluginInterface *>(plugininstance);

    const QString plname = ext->getInformation()->name;

    connect(ext, &ExtraPluginInterface::updateMessage,
                this, &TestWindow::setPluginOutput);

    setPluginOutput(tr("## [Plugin] %1 started.").arg(plname));

    QStringList args = getCommandList();

    if(!ext->functionMain(args.count(), &args)){
        QString success = ext->getMessage(MessageType::Success);
        if(success == "") success = tr("successfully completed.");

        setPluginOutput(tr("## [Plugin] %1 %2").arg(plname, success));

    }else{
        QString error = ext->getMessage(MessageType::Error);
        if(error == "") error = tr("failed.");

        setPluginOutput(tr("## [Plugin] %1 %2").arg(plname, error));
    }

    disconnect(ext, &ExtraPluginInterface::updateMessage,
                this, &TestWindow::setPluginOutput);
}

void TestWindow::closeClicked()
{
    qApp->closeAllWindows();
}

void TestWindow::receiveListClicked()
{
    ReceiveListDialog dialog;
    int result = dialog.exec();

    if(result == QDialog::Accepted){
        if(pluginloader != nullptr){
            ExtraPluginInterface *ext
                = qobject_cast<ExtraPluginInterface *>(plugininstance);

            ext->getInformation()
                ->settingwidget->receiveList(dialog.getArgumentsList());
        }
    }
}

void TestWindow::resetReceiveListClicked()
{
    if(pluginloader != nullptr){
        ExtraPluginInterface *ext
            = qobject_cast<ExtraPluginInterface *>(plugininstance);

        ext->getInformation()
            ->settingwidget->receiveList(QStringList());
    }
}

void TestWindow::getInformationClicked()
{
    if(pluginloader == nullptr) return;

    ExtraPluginInterface *ext
        = qobject_cast<ExtraPluginInterface *>(plugininstance);

    PluginInformation info = *ext->getInformation();

    QMessageBox msgBox;
    msgBox.setIcon(QMessageBox::Information);
    msgBox.setText(tr("Name    : %1\n"
                      "Version : %2\n"
                      "Author  : %3\n"
                      "ToolTip : \n%4")
                       .arg(info.name,
                            info.version,
                            info.author,
                            info.tooltip));
    msgBox.exec();
}

void TestWindow::setPluginOutput(QString message)
{
    ui->outputText->insertPlainText(message + "\n");
    ui->outputText->textCursor().movePosition(QTextCursor::End);
}

QStringList TestWindow::getCommandList()
{
    int count = ui->pluginTableWidget->rowCount();
    QStringList result;

    for (int i = 0; i < count; i++) {
        result.append(ui->pluginTableWidget->item(i, 0)->text());
    }

    return result;
}

bool TestWindow::loadPluginInstance(QString plfile)
{
    ExtraPluginInterface *ext = nullptr;

    if(pluginloader != nullptr){

        ext = qobject_cast<ExtraPluginInterface *>(plugininstance);
        if(ext->getInformation()->hassettingwidget){
            disconnect(ext->getInformation()->settingwidget, &PluginWidget::sendList, \
                       ui->pluginTableWidget, &DummyTable::insertSettingUpdate);
        }


        pluginloader->unload();

        delete pluginloader;
        pluginloader = nullptr;
        plugininstance = nullptr;
        ext = nullptr;

        ui->pluginTableWidget->setRowCount(0);
    }

    QFileInfo info(plfile);

    if(info.exists()){
        //check plugin can use
        pluginloader = new QPluginLoader(plfile);

        if(pluginloader->load()){
            plugininstance = pluginloader->instance();
            ext = qobject_cast<ExtraPluginInterface *>(plugininstance);

        }else{
            delete pluginloader;
            pluginloader = nullptr;
            plugininstance = nullptr;
            return false;
        }
    }else{
        return false;
    }

    // update gui widget
    if(ext != nullptr){
        if(ext->getInformation()->hassettingwidget){

            // get table items
            QStringList tmp;
            int tc = ui->pluginTableWidget->rowCount();

            for (int i = 0; i < tc; i++) {
                tmp.append(ui->pluginTableWidget->item(i, 0)->text());
            }

            // set current table items (set first for later signal avoid)
            // It gets a read access violation when the settingwidget option
            // is true but the widget is not set.
            ext->getInformation()->settingwidget->receiveList(tmp);

            PluginWidget *pw = ext->getInformation()->settingwidget;
            pw->setPalette(ui->pluginFrame->palette());

            ui->scrollArea->setWidget(pw);

            // connect to ctableplugin
            connect(ext->getInformation()->settingwidget, &PluginWidget::sendList, \
                       ui->pluginTableWidget, &DummyTable::insertSettingUpdate);

            ui->actionReceiveList->setEnabled(true);
            ui->actionResetReceiveList->setEnabled(true);

        }else{
            ui->scrollArea->setWidget(new QLabel(tr("This plugin has no widget.")));
        }

        ui->actionPlay->setEnabled(true);
        ui->actionGetInformation->setEnabled(true);

    }else{
        ui->scrollArea->takeWidget();
        ui->actionPlay->setEnabled(false);
        ui->actionReceiveList->setEnabled(false);
        ui->actionResetReceiveList->setEnabled(false);
        ui->actionGetInformation->setEnabled(false);
    }

    return true;
}

