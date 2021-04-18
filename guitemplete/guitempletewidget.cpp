#include "guitempletewidget.h"
#include "ui_guitempletewidget.h"

GuiTempleteWidget::GuiTempleteWidget(QWidget *parent) :
    PluginWidget(parent),
    ui(new Ui::GuiTempleteWidget)
{
    ui->setupUi(this);

    connect(ui->countButton, &QPushButton::clicked,
            this, &GuiTempleteWidget::countClicked);
}

GuiTempleteWidget::~GuiTempleteWidget()
{
    delete ui;
}

void GuiTempleteWidget::receiveList(QStringList args)
{
    QString result = "";
    for(QString& arg : args){
        result.append(arg);
        result.append('\n');
    }

    ui->plainTextEdit->setPlainText(result);
}

void GuiTempleteWidget::countClicked()
{
    static int counter = 0;
    counter++;

    QStringList list;

    for(int i = 0; i < counter; i++){
        list.append(QString::number(i+1));
    }
    emit sendList(list);
}
