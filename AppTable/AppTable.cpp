#include "AppTable.h"
#include <stdlib.h>
using namespace Prog4;

Table t;
AppTable::AppTable(QWidget* parent) : QWidget(parent)
{
    layout = new QGridLayout();
    addButton = new QPushButton("Insert");
    saleButton = new QPushButton("Sale");
    showButton = new QPushButton("Show");

    editType = new QLineEdit(this);
    editName = new QLineEdit();
    editCountry = new QLineEdit();
    editFirm = new QLineEdit();
    editCount = new QLineEdit();
    editCost = new QLineEdit();
    editDop = new QLineEdit();
    msg = new QMessageBox();
    labelType = new QLabel("Enter type of product", this);
    labelType->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    labelName = new QLabel("Enter product name: ", this);
    labelName->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    labelCountry = new QLabel("Enter country of product: ", this);
    labelCountry->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    labelFirm = new QLabel("Enter firm of product: ", this);
    labelFirm->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    labelCount = new QLabel("Enter quantity of product: ", this);
    labelCount->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    labelCost = new QLabel("Enter cost of product: ", this);
    labelCost->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    labelDop = new QLabel("Enter additional info about product: ", this);
    labelDop->setAlignment(Qt::AlignRight | Qt::AlignCenter);
    layout->addWidget(labelType, 0, 0);
    layout->addWidget(editType, 0, 1);
    layout->addWidget(labelName, 1, 0);
    layout->addWidget(editName, 1, 1);
    layout->addWidget(labelCountry, 2, 0);
    layout->addWidget(editCountry, 2, 1);
    layout->addWidget(labelFirm, 3, 0);
    layout->addWidget(editFirm, 3, 1);
    layout->addWidget(labelCount, 4, 0);
    layout->addWidget(editCount, 4, 1);
    layout->addWidget(labelCost, 5, 0);
    layout->addWidget(editCost, 5, 1);
    layout->addWidget(labelDop, 6, 0);
    layout->addWidget(editDop, 6, 1);


    layout->addWidget(addButton, 7, 0);
    layout->addWidget(saleButton, 7, 1);
    layout->addWidget(showButton, 7, 2);
    connect(showButton, SIGNAL(clicked(bool)), this, SLOT(getTable()));
    connect(addButton, SIGNAL(clicked(bool)), this, SLOT(add()));
    connect(saleButton, SIGNAL(clicked(bool)), this, SLOT(sale()));

    setLayout(layout);

}


void AppTable::getTable() {
    std::string str = t.getEl();
    msg->setText(QString::fromStdString(str));
    msg->show();
}

void AppTable::add() {
    std::string name = editName->text().toStdString();
    std::string typeStr = editType->text().toStdString();
    char type = typeStr[0];
    std::string country = editCountry->text().toStdString();
    std::string firm = editFirm->text().toStdString();
    int count = editCount->text().toInt();
    int cost = editCost->text().toInt();
    if (type == 'w') {
        int CW = editDop->text().toInt();
        Prog4::wDescriptor* w1 = new Prog4::wDescriptor;
        w1->setCost(cost);
        w1->setCount(count);
        w1->setCountWholesale(CW);
        w1->setFirm(firm);
        w1->setCountry(country);
        w1->setName(name);
        Prog4::descriptor* val = t.find(get_md5(w1->getName()));
        if (val == nullptr)
            t.add(*w1);
        else {
            w1->setCount(val->getCount() + w1->getCount());
            t.del(val->getName());
            t.add(*w1);
        }
    }
    if (type == 'r') {
        int CW = editDop->text().toInt();
        Prog4::rDescriptor* r1 = new Prog4::rDescriptor;
        r1->setCost(cost);
        r1->setCount(count);
        r1->setAllowance(CW);
        r1->setFirm(firm);
        r1->setCountry(country);
        r1->setName(name);
        Prog4::descriptor* val = t.find(get_md5(r1->getName()));
        if (val == nullptr)
            t.add(*r1);
        else {
            r1->setCount(val->getCount() + r1->getCount());
            t.del(val->getName());
            t.add(*r1);
        }
    }
}

void AppTable::sale() {
    std::string name = editName->text().toStdString();
    int count = editCount->text().toInt();
    std::string typeStr = editType->text().toStdString();
    char type = typeStr[0];
    descriptor* newVal = t.find(get_md5(name));
    int all = 0;
    if (newVal != nullptr) {
        t.del(name);
        all = newVal->sale(count);
        t.add(*newVal);
    }
    if (all >= 0) {
        std::string str = "Amount of sale: ";
        str += std::to_string(all);
        msg->setText(QString::fromStdString(str));
        msg->show();
    }
    else {
        std::string str = "Amount of sold product more than available amount";
        msg->setText(QString::fromStdString(str));
        msg->show();
    }
    
}
AppTable::~AppTable()
{
    delete layout;
    delete editCost, editCount, editFirm, editCountry, editDop, editName, editType;
    delete labelName, labelCost, labelCount, labelCountry, labelDop, labelFirm;
    delete showButton, addButton, saleButton;
    delete msg;
    
}