#include <QtWidgets>
#include "road.h"
class MainWindow : public QMainWindow {
public:
	MainWindow(Road* _road);
	void buttonRoad1Click();
private:
	QLabel* widthLabel;
	QPushButton* buttonRoad1;
	QPushButton* buttonRoad2;
	QLineEdit* widthEdit;
	Road* road1;
};

MainWindow::MainWindow(Road* _road) {
	setFixedSize(700, 400);
	setWindowTitle("Two roads v8.2");
	QFont labelFont("Time", 72, QFont::Normal);
	QFont buttonFont("Time", 12, QFont::Normal);
	widthLabel = new QLabel("Width:", this);
	widthLabel->setGeometry(0, 0, 500, 150);
	widthLabel->setFont(labelFont);
	widthLabel->setText("Width:" + QString::number(_road->Width));
	buttonRoad1 = new QPushButton("road 1", this);
	buttonRoad1->setGeometry(20, 170, 200, 70);
	buttonRoad1->setFont(buttonFont);
	buttonRoad2 = new QPushButton("road 2", this);
	buttonRoad2->setGeometry(240, 170, 200, 70);
	buttonRoad2->setFont(buttonFont);

	widthEdit = new QLineEdit(this);
	widthEdit->setGeometry(20, 260, 200, 70);
	road1 = _road;
	connect(buttonRoad1, &QPushButton::clicked,
		this, &MainWindow::buttonRoad1Click);
}

void MainWindow::buttonRoad1Click() {
	QString strWidth;
	strWidth = widthEdit.text;
	road1->Width = 4;
	//widthLabel->setText("Width:"+ QString::number(road1->Width));
	widthLabel->setText("Width:" + strWidth);
}

int main(int argc, char* argv[]) {
	Road road(6);

	QApplication app(argc, argv);
	MainWindow mainWin(&road);
	mainWin.show();
	return app.exec();
}
