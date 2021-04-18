#ifndef RECEIVELISTDIALOG_H
#define RECEIVELISTDIALOG_H

#include <QDialog>

namespace Ui {
class ReceiveListDialog;
}

class ReceiveListDialog : public QDialog
{
    Q_OBJECT

public:
    explicit ReceiveListDialog(QWidget *parent = nullptr);
    virtual ~ReceiveListDialog() override;

    QStringList getArgumentsList();

private:
    Ui::ReceiveListDialog *ui;
};

#endif // RECEIVELISTDIALOG_H
