#ifndef FILEVIEWWIDGET_H
#define FILEVIEWWIDGET_H

#include <QListWidget>
class fileViewWidget : public QListWidget {
    Q_OBJECT

    public:
        fileViewWidget(QWidget *parent = nullptr);
        ~fileViewWidget();
        void changeDirectory(QString directory);
        void goUp();
        void activateRow(QString path);

    public slots:
        void currentItemChanged(QListWidgetItem * current, QListWidgetItem * previous);

    private:
        QString currentdirectory;
};

#endif // FILEVIEWWIDGET_H
