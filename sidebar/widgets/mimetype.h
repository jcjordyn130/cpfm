#ifndef MIMETYPEWIDGET_H
#define MIMETYPEWIDGET_H
#include <QLabel>
#include <QListWidgetItem>

class mimetypeWidget : public QLabel {
    Q_OBJECT

    public:
        mimetypeWidget(QWidget *parent = nullptr);
        ~mimetypeWidget();
        void Update(QListWidgetItem *newitem, QListWidgetItem *olditem);
};

#endif // FILEVIEWWIDGET_H
