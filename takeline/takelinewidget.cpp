#include "takelinewidget.h"
#include "ui_takelinewidget.h"

TakeLineWidget::TakeLineWidget(QWidget *parent) :
    PluginWidget(parent),
    ui(new Ui::TakeLineWidget)
{
    ui->setupUi(this);
}

TakeLineWidget::~TakeLineWidget()
{
    delete ui;
}

void TakeLineWidget::receiveList(QStringList args)
{
    int counter = args.count();

    // block unexpected sendList signal
    this->blockSignals(true);

    if(counter > 0) ui->plainTextEdit->setPlainText(args.at(TakeLineList::SourceOrString));
    if(counter > 1) ui->removelineEdit->setText(args.at(TakeLineList::RemoveLineNumber));
    if(counter > 2) ui->returnLineEdit->setText(args.at(TakeLineList::LocalVariant));


    this->blockSignals(false);
}

void TakeLineWidget::updateArguments()
{
    QStringList converted;

    converted.append(settingargs.value(TakeLineList::SourceOrString, ""));
    converted.append(settingargs.value(TakeLineList::RemoveLineNumber, ""));
    converted.append(settingargs.value(TakeLineList::LocalVariant, ""));

    emit sendList(converted);
}

void TakeLineWidget::on_plainTextEdit_textChanged()
{
    settingargs.insert(TakeLineList::SourceOrString, ui->plainTextEdit->toPlainText());
    updateArguments();
}

void TakeLineWidget::on_removelineEdit_textChanged(const QString &arg1)
{
    settingargs.insert(TakeLineList::RemoveLineNumber, arg1);
    updateArguments();
}

void TakeLineWidget::on_returnLineEdit_textChanged(const QString &arg1)
{
    settingargs.insert(TakeLineList::LocalVariant, arg1);
    updateArguments();
}
