#include "mainwindow.h"
#include "./ui_mainwindow.h"
#include <vector>
#include <QKeyEvent>
#include <QDirIterator>
#include <QDir>
#include <iostream>
#include <filesystem>
#include "fileviewwidget.h"

MainWindow::MainWindow(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::MainWindow)
{
    ui->setupUi(this);

    // Setup the sidebar widgets.
    connect(ui->fileView, &QListWidget::currentItemChanged,
            ui->mimelabel, &mimetypeWidget::Update);

    connect(ui->fileView, &QListWidget::currentItemChanged,
            ui->filesizelabel, &filesizeWidget::Update);

    // Bootstrap with the first listing.
    ui->fileView->changeDirectory("/");
}

void MainWindow::keyPressEvent(QKeyEvent *event) {
    std::cout << "Key Pressed: " << event->text().toStdString() << std::endl;
    int key = event->key();
    if (key == Qt::Key_Right) {
        // Right key handler
        // Activate the child listing.
        QString currentrow = ui->fileView->currentItem()->text();
        ui->fileView->activateRow(currentrow);
    } else if (key == Qt::Key_Left) {
        // Left key handler.
        ui->fileView->goUp();
    }
}

MainWindow::~MainWindow()
{
    delete ui;
}

