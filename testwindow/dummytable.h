#ifndef DUMMYTABLE_H
#define DUMMYTABLE_H

#include <QTableWidget>
#include <QWidget>
#include <QApplication>
#include <QHeaderView>
#include <QMenu>

class DummyTable : public QTableWidget
{
    Q_OBJECT
public:
    explicit DummyTable(QWidget *parent = nullptr);
    ~DummyTable() override;

    void updateTableList(QStringList *list);

signals:
    void updatePluginWidget(QStringList, int);

public slots:
    void insertSettingUpdate(QStringList list);

private slots:
    void onCustomContextMenu(const QPoint &point);
    void addAction();
    void deleteAction();
    void editAction();

private:
    QMenu *contextMenu;
    QAction *actionAdd;
    QAction *actionDelete;
    QAction *actionEdit;
};

#endif // DUMMYTABLE_H
