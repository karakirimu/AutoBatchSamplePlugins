#include "filetextreplacewidget.h"
#include "ui_filetextreplacewidget.h"

FileTextReplaceWidget::FileTextReplaceWidget(QWidget *parent) :
    PluginWidget(parent),
    ui(new Ui::FileTextReplaceWidget)
{
    ui->setupUi(this);

    connect(ui->inputEdit, &QLineEdit::textChanged,
            this, &FileTextReplaceWidget::inputEditChanged);
    connect(ui->outputEdit, &QLineEdit::textChanged,
            this, &FileTextReplaceWidget::outputEditChanged);
    connect(ui->inputToolButton, &QToolButton::clicked,
            this, &FileTextReplaceWidget::inputToolButtonClicked);
    connect(ui->outputToolButton, &QToolButton::clicked, this,
            &FileTextReplaceWidget::outputToolButtonClicked);

    connect(ui->searchEdit, &QLineEdit::textChanged,
            this, &FileTextReplaceWidget::searchEditChanged);
    connect(ui->replaceEdit, &QLineEdit::textChanged,
            this, &FileTextReplaceWidget::replaceEditChanged);
}

FileTextReplaceWidget::~FileTextReplaceWidget()
{
    delete ui;
}

void FileTextReplaceWidget::receiveList(QStringList args)
{
    int counter = args.count();

    // block unexpected sendList signal
    this->blockSignals(true);

    // reset ui
    ui->inputEdit->clear();
    ui->outputEdit->clear();
    ui->searchEdit->clear();
    ui->replaceEdit->clear();

    if(counter > 0) ui->inputEdit->setText(args.at(FileTextReplaceList::InputFile));
    if(counter > 1) ui->outputEdit->setText(args.at(FileTextReplaceList::OutputFile));
    if(counter > 2) ui->searchEdit->setText(args.at(FileTextReplaceList::SearchWord));
    if(counter > 3) ui->replaceEdit->setText(args.at(FileTextReplaceList::ReplaceWord));

    this->blockSignals(false);
}

void FileTextReplaceWidget::updateArguments()
{
    QStringList converted;

    converted.append(settingargs.value(FileTextReplaceList::InputFile, ""));
    converted.append(settingargs.value(FileTextReplaceList::OutputFile, ""));
    converted.append(settingargs.value(FileTextReplaceList::SearchWord, ""));
    converted.append(settingargs.value(FileTextReplaceList::ReplaceWord, ""));

    emit sendList(converted);
}

void FileTextReplaceWidget::inputEditChanged(const QString &arg1)
{
    settingargs.insert(FileTextReplaceList::InputFile, arg1);
    updateArguments();
}

void FileTextReplaceWidget::inputToolButtonClicked()
{
    QFileDialog dialog(this);
    dialog.setFileMode(QFileDialog::ExistingFile);
    QString file
        = dialog.getOpenFileName(this,
                                 tr("Open"),
                                 QDir::currentPath(),
                                 tr("File ") + "(*.*)");

    if(file != "") ui->inputEdit->setText(file);
}

void FileTextReplaceWidget::outputEditChanged(const QString &arg1)
{
    settingargs.insert(FileTextReplaceList::OutputFile, arg1);
    updateArguments();
}

void FileTextReplaceWidget::outputToolButtonClicked()
{
    QFileDialog dialog(this);
    QString file
        = dialog.getSaveFileName(this,
                                 tr("Save"),
                                 QDir::currentPath(),
                                 tr("File ") + "(*.*)");

    if(file != "") ui->outputEdit->setText(file);
}

void FileTextReplaceWidget::searchEditChanged(const QString &arg1)
{
    settingargs.insert(FileTextReplaceList::SearchWord, arg1);
    updateArguments();
}

void FileTextReplaceWidget::replaceEditChanged(const QString &arg1)
{
    settingargs.insert(FileTextReplaceList::ReplaceWord, arg1);
    updateArguments();
}
