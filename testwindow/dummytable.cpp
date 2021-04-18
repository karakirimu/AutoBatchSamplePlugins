#include "dummytable.h"

DummyTable::DummyTable(QWidget *parent)
    : QTableWidget(parent)
{
    setContextMenuPolicy(Qt::CustomContextMenu);
    connect(this, &QWidget::customContextMenuRequested,
            this, &DummyTable::onCustomContextMenu);

    //init menu context
    contextMenu = new QMenu(this);

    //set basic items
    actionAdd = contextMenu->addAction("Add");
    actionDelete = contextMenu->addAction("Delete");
    actionEdit = contextMenu->addAction("Edit");

    //connect signals
    connect(actionAdd, &QAction::triggered, this, &DummyTable::addAction);
    connect(actionDelete, &QAction::triggered, this, &DummyTable::deleteAction);
    connect(actionEdit, &QAction::triggered, this, &DummyTable::editAction);

    //init table size
    setColumnCount(1);
    setRowCount(0);

    //adjust row
    resizeRowsToContents();

    //adjust column
    horizontalHeader()->setSectionResizeMode(0, QHeaderView::Stretch);

    //set header label
    setHorizontalHeaderLabels((QStringList() << tr("Executable file / Arguments")));
}

DummyTable::~DummyTable()
{
    delete contextMenu;
}

/**
 * @fn DummyTable::updateTableList
 * @brief The process of replacing all the contents of the table.
 */
void DummyTable::updateTableList(QStringList *list)
{
    int counter = list->count();
    clearContents();
    setRowCount(counter);

    for(int i = 0; i < counter; i++){
        this->blockSignals(true);
        this->setItem(i, 0, new QTableWidgetItem(list->at(i)));
        this->blockSignals(false);
    }
}

/**
 * @fn DummyTable::insertSettingUpdate
 * @brief A slot that receives as an argument the UI state
 *        change of the widget created by the plugin.
 * @param list Argument list updated from plugin widget.
 */
void DummyTable::insertSettingUpdate(QStringList list)
{
    clearContents();

    int counter = list.count();
    setRowCount(counter);

    for(int i = 0; i < counter; i++){
        this->blockSignals(true);
        this->setItem(i, 0, new QTableWidgetItem(list.at(i)));
        this->blockSignals(false);
    }
}

void DummyTable::onCustomContextMenu(const QPoint &point)
{
    contextMenu->popup(mapToGlobal(point));
}

void DummyTable::addAction()
{
    int row = this->rowCount();
    this->insertRow(row);

    //for useability
    this->setCurrentItem(itemAt(row,0));
    this->selectRow(row);
}

void DummyTable::deleteAction()
{
    //if rowcount is zero.
    if(this->rowCount() == 0) return;

    QModelIndexList lists = this->selectedIndexes();

    while(!lists.empty()){
        this->removeRow(lists.at(0).row());
        lists = this->selectedIndexes();
    }
}

void DummyTable::editAction()
{
    this->clearSelection();
    this->edit(currentIndex());
}
