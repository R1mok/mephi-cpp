#ifndef WIDGET_H
#define WIDGET_H

#include <QWidget>
#include <QPushButton>
#include <QLabel>
#include <QLineEdit>
#include <QVBoxLayout>
#include <QMessageBox>
#include <iostream>
#include <string>

#include "descriptor.h"
#include "wDescriptor.h"
#include "rDescriptor.h"
#include "md5.h"
#include "Table.h"
#include "MyMap.h"

class AppTable : public QWidget
{
    Q_OBJECT


private:
    QGridLayout* layout;
    QLineEdit* editType, *editName, *editCountry, *editFirm, *editCount, *editCost, *editDop;
    QLabel* labelType, * labelName, * labelCountry, * labelFirm, * labelCount, * labelCost, * labelDop;
    QPushButton* showButton, *addButton, *saleButton;
    QMessageBox* msg;

public slots:
    void getTable();
    void add();
    void sale();
public:
    AppTable(QWidget* parent = 0);
    ~AppTable();
};

#endif // WIDGET_H