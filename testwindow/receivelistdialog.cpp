#include "receivelistdialog.h"
#include "ui_receivelistdialog.h"

ReceiveListDialog::ReceiveListDialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::ReceiveListDialog)
{
    ui->setupUi(this);
}

ReceiveListDialog::~ReceiveListDialog()
{
    delete ui;
}

QStringList ReceiveListDialog::getArgumentsList()
{
    int count = ui->sendTableWidget->rowCount();
    QStringList result;

    for (int i = 0; i < count; i++) {
        result.append(ui->sendTableWidget->item(i, 0)->text());
    }

    return result;
}
