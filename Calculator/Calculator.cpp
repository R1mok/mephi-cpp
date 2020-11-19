#include "Calculator.h"
#include "BigInt.h"

using namespace lab_oop3;
Calculator::Calculator(QWidget * parent) : QWidget(parent) {
	displaystring = new QLabel("");
	displaystring->setMinimumSize(150, 50);
	QChar aButtons[4][4] = {
	 {'7', '8', '9', '~'},
	 {'4', '5', '6', '/' },
	 {'1', '2', '3', '*'},
	 {'-', '0', '+', '='}
	};

	QGridLayout* myLayout = new QGridLayout;
	myLayout->addWidget(displaystring, 0, 0, 1, 4);
	myLayout->addWidget(createButton("CE"), 1, 3);
	for (int i = 0; i < 4; ++i) {
		for (int j = 0; j < 4; ++j) {
			myLayout->addWidget(createButton(aButtons[i][j]), i + 2, j);
		}
	}
	setLayout(myLayout);
}
QPushButton* Calculator::createButton(const QString& str) {
	QPushButton* pcmd = new QPushButton(str);
	pcmd->setMinimumSize(40, 40);
	connect(pcmd, SIGNAL(clicked()), this, SLOT(slotButtonClicked()));
	return pcmd;
}
void Calculator::calculate() {
	Big_decimal dResult;
	long dOperand2 = stack.pop().toDouble();
	Big_decimal op2(dOperand2);
	QString strOperation = stack.pop();
	if (strOperation == "/") { dResult = op2.Div_ten(); }
	else if (strOperation == "~") { dResult = ~op2; }
	else if (strOperation == "*") { dResult = op2.Prod_ten(); }
	else {
		long dOperand1 = stack.pop().toDouble();
		Big_decimal op1(dOperand1);
		if (strOperation == "+") { dResult = op2 + op1; }
		else if (strOperation == "-") { dResult = op2 - op1; }
	}
	int res = 0;
	for (int i = 1; i <= dResult.getLength(); ++i) {
		int a = dResult.getDigit(i) - '0';
		res += a * pow(10,i-1);
	}
	if (dResult.getDigit(0) == '1')
		res *= -1;
	displaystring->setText(QString("%1").arg(double(res), 0, 'f', 0));
}
void Calculator::slotButtonClicked() {
	QString str = ((QPushButton*)sender())->text(); // get text from pushed button
	if (str == "CE") {  // clear string
		stack.clear(); 
		displaystring->setText("");
		return;
	}

	QString text = displaystring->text();
	int len = text.length();
	QString last = "";
	if (len > 0) 
		last = text.right(1); // right simbol 

	if (((len == 0 && stack.count() == 0) ||
		((stack.count() == 2 && len > 1 && (last == "+" || last == "-")))) &&
		(str.contains(QRegExp("[0-9]")) || str == "-")) {
		text = str;
	}
	else if ((text + str).contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))) {
		text += str; // add simbol, while input number
	}
	else if (text.contains(QRegExp("^-?[0-9]+\\.?[0-9]*$"))) { // number already wrote
		if (str == "*" || str == "/" || str == "+" || str == "-" || str == "=" || str == "~") { // calculate
			if (stack.count() == 2) { // number and activity
				stack.push(text); 
				calculate();
				text = displaystring->text(); // get result
			}
			if (str == "~" || str == "/" || str == "*") {
				stack.push(str);
				stack.push(text);
				text += str;
				calculate();
				text = displaystring->text();
			} else if (str != "=") { // one by one
				stack.push(text);
				text += str;
				stack.push(str);
			}
		}
	}
	displaystring->setText(text);
}