#include "mainwindow.h"
#include "ui_mainwindow.h"

#include <QFileDialog>
#include <QMessageBox>

MainWindow::MainWindow(QWidget *parent) :
    QMainWindow(parent),
    ui(new Ui::MainWindow)
{
    ui->setupUi(this);
    connect(this->ui->actionOpen, SIGNAL(triggered(bool)), this, SLOT(ActionOpen_activated()));
    connect(this->ui->actionClose, SIGNAL(triggered(bool)), this, SLOT(ActionClose_activated()));
}

MainWindow::~MainWindow()
{
    delete ui;
}

void MainWindow::ActionOpen_activated()
{
    QString filename = QFileDialog::getOpenFileName(this, "Open map", QString(), "*.sitx");
    if (filename.isEmpty() == false)
    {
        MapHandle = mapOpenAnyData(filename.utf16());
        if (MapHandle == 0)
        {
            QMessageBox::information(this, "Error open map", QString("Map open failed") + filename, "Ok");
        }
    }
}

void MainWindow::ActionClose_activated()
{
    if (MapHandle)
        mapCloseData(MapHandle);
    MapHandle = 0;
}


