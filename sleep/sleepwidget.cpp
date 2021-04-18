#include "sleepwidget.h"
#include "ui_sleepwidget.h"

SleepWidget::SleepWidget(QWidget *parent) :
    PluginWidget(parent),
    ui(new Ui::SleepWidget)
{
    ui->setupUi(this);
}

SleepWidget::~SleepWidget()
{
    delete ui;
}

void SleepWidget::receiveList(QStringList args)
{
    int counter = args.count();

    // block unexpected sendList signal
    this->blockSignals(true);

    if(counter > 0) ui->timerLineEdit->setText(args.at(0));

    this->blockSignals(false);
}

void SleepWidget::on_timerLineEdit_textChanged(const QString &arg1)
{
    emit sendList(QStringList() << arg1);
}
