#include "mimetype.h"
#include <iostream>
#include <QDirIterator>
#include <QDir>
#include <QFileInfo>
#include <QLabel>
#include <QMimeDatabase>
#include <QtDebug>
#include "../../fileviewwidget.h"

mimetypeWidget::mimetypeWidget(QWidget *parent) : QLabel(parent) {
};

mimetypeWidget::~mimetypeWidget() {

};

void mimetypeWidget::mimetypeWidget::Update(QListWidgetItem *newitem, QListWidgetItem *olditem) {
    if (newitem == nullptr) {
        qInfo() << "mimetypeWidget::Update called with NULL item";
        return;
    }

    QMimeDatabase db;
    QMimeType type = db.mimeTypeForFile(newitem->text());
    std::cout << "Mime type for " << newitem->text().toStdString() << ": " << type.name().toStdString() << std::endl;
    setText(type.name());
}
