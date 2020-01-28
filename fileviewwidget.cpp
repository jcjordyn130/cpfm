#include "fileviewwidget.h"
#include <iostream>
#include <QDirIterator>
#include <QDir>
#include <QFileInfo>
#include <QDesktopServices>
#include <QUrl>
#include <QDebug>

fileViewWidget::fileViewWidget(QWidget *parent) : QListWidget(parent) {
   // connect(this, SIGNAL(currentItemChanged(QListWidgetItem*, QListWidgetItem*)),
    //        this, SLOT(currentItemChanged(QListWidgetItem*, QListWidgetItem*)) );
};

fileViewWidget::~fileViewWidget() {

};

void fileViewWidget::activateRow(QString path) {
    std::cout << "Row activated: " << path.toStdString() << std::endl;;
    QFileInfo pathinfo = QFileInfo(path);
    if ( pathinfo.isDir() ) {
        // The activated row is a directory, go into it.
        std::cout << "Row is a directory..." << std::endl;
        changeDirectory(path);
    } else if ( pathinfo.isFile() ) {
        // The activated row is a file, open it.
        // TODO: Implement file opening code.
        std::cout << "Row is a file..." << std::endl;
        QDesktopServices::openUrl(QUrl::fromLocalFile(path));
    }
}

void fileViewWidget::changeDirectory(QString directory) {
    // Clear the entries in the list.
    clear();
    currentdirectory = directory;

    std::cout << "Directory changed to: " << directory.toStdString() << std::endl;
    QDirIterator it(directory, QDir::NoFilter);
    while (it.hasNext()) {
        QString child = it.next();

        if (child.contains("/..") || child.contains("/.")) {
            // Skip the special directories on *nix.
            continue;
        }

        // Add it to the list.
        addItem(child);
    }

    this->setCurrentRow(0);
}

void fileViewWidget::goUp() {
    std::cout << "Going up a directory..." << std::endl;
    QDir directory = QDir(currentdirectory);

    if (directory.cdUp()) {
        changeDirectory(directory.absolutePath());
    } else {
        qInfo() << "We can't go up...";
    }
}

void fileViewWidget::currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous) {
    if (current == nullptr) {
        std::cout << "currentItemChanged() called with NULL item." << std::endl;
        return;
    }

    std::cout << "Current selection changed: " << current->text().toStdString() << std::endl;
}
