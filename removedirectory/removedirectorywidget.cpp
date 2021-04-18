#include "removedirectorywidget.h"
#include "ui_removedirectorywidget.h"

RemoveDirectoryWidget::RemoveDirectoryWidget(QWidget *parent) :
    PluginWidget(parent),
    ui(new Ui::RemoveDirectoryWidget)
{
    ui->setupUi(this);

    connect(ui->rmpathLineEdit,&QLineEdit::textChanged,
            this, &RemoveDirectoryWidget::rmpathTextChanged);
    connect(ui->fileRemoveCheckBox, &QCheckBox::stateChanged,
            this, &RemoveDirectoryWidget::fileRemoveCheckBoxChanged);
    connect(ui->rmToolButton, &QToolButton::clicked,
            this, &RemoveDirectoryWidget::rmToolButtonClicked);
}

RemoveDirectoryWidget::~RemoveDirectoryWidget()
{
    delete ui;
}

void RemoveDirectoryWidget::receiveList(QStringList args)
{
    int counter = args.count();

    // block unexpected sendList signal
    this->blockSignals(true);

    // reset ui
    ui->rmpathLineEdit->clear();
    ui->fileRemoveCheckBox->setChecked(false);

    if(counter > 0)
        ui->rmpathLineEdit->setText(args.at(RemoveDirectoryList::RemovePath));

    if(counter > 1 && args.at(RemoveDirectoryList::FileInclude) == "-rf")
        ui->fileRemoveCheckBox->setChecked(true);


    this->blockSignals(false);
}

void RemoveDirectoryWidget::updateArguments()
{
    QStringList converted;
    converted.append(settingargs.value(RemoveDirectoryList::RemovePath, ""));
    converted.append(settingargs.value(RemoveDirectoryList::FileInclude, ""));

    emit sendList(converted);
}

void RemoveDirectoryWidget::rmpathTextChanged(const QString &arg1)
{
    settingargs.insert(RemoveDirectoryList::RemovePath, arg1);
    updateArguments();
}

void RemoveDirectoryWidget::rmToolButtonClicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::DirectoryOnly);
    dialog.setOption(QFileDialog::ShowDirsOnly, true);
    QString dir = dialog.getExistingDirectory(this,
                                              tr("Open Directory"),
                                              QDir::currentPath());

    if(dir != "") ui->rmpathLineEdit->setText(dir);
}

void RemoveDirectoryWidget::fileRemoveCheckBoxChanged(int arg1)
{
    if(arg1 == Qt::CheckState::Checked){
        settingargs.insert(RemoveDirectoryList::FileInclude, "-rf");
    }else{
        settingargs.insert(RemoveDirectoryList::FileInclude, "");
    }
    updateArguments();
}
