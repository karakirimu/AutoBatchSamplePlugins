#include "downloadwidget.h"
#include "ui_downloadwidget.h"

DownloadWidget::DownloadWidget(QWidget *parent) :
    PluginWidget(parent),
    ui(new Ui::DownloadWidget)
{
    ui->setupUi(this);

    connect(ui->urlRadioButton, &QRadioButton::clicked,
            this, &DownloadWidget::urlRadioButtonClicked);
    connect(ui->urlFileRadioButton, &QRadioButton::clicked,
            this, &DownloadWidget::urlFileRadioButtonClicked);
    connect(ui->pathEdit, &QLineEdit::textChanged,
            this, &DownloadWidget::lineEditChanged);
    connect(ui->folderEdit, &QLineEdit::textChanged,
            this, &DownloadWidget::folderLineEditChanged);
    connect(ui->fileOpenToolButton, &QToolButton::clicked,
            this, &DownloadWidget::openFile);
    connect(ui->folderOpenToolButton, &QToolButton::clicked,
            this, &DownloadWidget::openFolder);
}

DownloadWidget::~DownloadWidget()
{
    delete ui;
}

void DownloadWidget::receiveList(QStringList args)
{
    int counter = args.count();

    // block unexpected sendList signal
    this->blockSignals(true);

    // reset ui
    ui->pathEdit->clear();
    ui->folderEdit->clear();
    ui->urlRadioButton->setChecked(true);

    for(int i = 0; i < counter; i+=2){
        QString arg = args.at(i);
        if(counter % 2 == 0 ){
            if(arg == "-i"){
                ui->urlRadioButton->setChecked(true);
                settingargs.insert(DownloadArgumentList::InputType, "-i");
                settingargs.insert(DownloadArgumentList::InputPath, args.at(i+1));
                ui->pathEdit->setText(settingargs.value(DownloadArgumentList::InputPath));
            }
            if(arg == "-fi"){
                ui->urlFileRadioButton->setChecked(true);
                settingargs.insert(DownloadArgumentList::InputType, "-fi");
                settingargs.insert(DownloadArgumentList::InputPath, args.at(i+1));
                ui->pathEdit->setText(settingargs.value(DownloadArgumentList::InputPath));
            }
            if(arg == "-o"){
                settingargs.insert(DownloadArgumentList::OutputPath, args.at(i+1));
                ui->folderEdit->setText(settingargs.value(DownloadArgumentList::OutputPath));
            }
        }
    }

    this->blockSignals(false);
}

void DownloadWidget::updateArguments()
{
    QStringList args;
    args.append(settingargs.value(DownloadArgumentList::InputType, "-i"));
    args.append(settingargs.value(DownloadArgumentList::InputPath, ""));

    if(settingargs.contains(DownloadArgumentList::OutputPath)){
        args.append("-o");
        args.append(settingargs.value(DownloadArgumentList::OutputPath));
    }

    // Execute sendList(), the setting value will be reflected in the TableWidget.
    emit sendList(args);
}

void DownloadWidget::urlRadioButtonClicked()
{
    settingargs.insert(DownloadArgumentList::InputType, "-i");
    ui->pathEdit->setPlaceholderText(tr("URL"));
    updateArguments();
}

void DownloadWidget::urlFileRadioButtonClicked()
{
    settingargs.insert(DownloadArgumentList::InputType, "-fi");
    ui->pathEdit->setPlaceholderText(tr("Text file containing a list of URLs"));
    updateArguments();
}

void DownloadWidget::lineEditChanged(QString text)
{
    settingargs.insert(DownloadArgumentList::InputPath, text);
    updateArguments();
}

void DownloadWidget::folderLineEditChanged(QString text)
{
    settingargs.insert(DownloadArgumentList::OutputPath, text);
    updateArguments();
}

void DownloadWidget::openFile()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    QString file
        = dialog.getOpenFileName(this,
                                 tr("Open"),
                                 QDir::currentPath(),
                                 tr("Text File ") + "(*.*)");

    if(file != "") ui->pathEdit->setText(file);
}

void DownloadWidget::openFolder()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    QString dir = dialog.getExistingDirectory(this,
                                 tr("Open Directory"),
                                 QDir::currentPath());

    if(dir != "") ui->folderEdit->setText(dir);
}
