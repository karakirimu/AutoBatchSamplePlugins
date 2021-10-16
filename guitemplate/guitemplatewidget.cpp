#include "guitemplatewidget.h"
#include "ui_guitemplatewidget.h"

GuiTemplateWidget::GuiTemplateWidget(QWidget *parent) :
    PluginWidget(parent),
    ui(new Ui::GuiTemplateWidget)
{
    ui->setupUi(this);

    connect(ui->countButton, &QPushButton::clicked,
            this, &GuiTemplateWidget::countClicked);
}

GuiTemplateWidget::~GuiTemplateWidget()
{
    delete ui;
}

void GuiTemplateWidget::receiveList(QStringList args)
{
    QString result = "";
    for(QString& arg : args){
        result.append(arg);
        result.append('\n');
    }

    ui->plainTextEdit->setPlainText(result);
}

void GuiTemplateWidget::countClicked()
{
    static int counter = 0;
    counter++;

    QStringList list;

    for(int i = 0; i < counter; i++){
        list.append(QString::number(i+1));
    }
    emit sendList(list);
}
