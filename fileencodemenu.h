#ifndef FILEENCODEMENU_H
#define FILEENCODEMENU_H

#include <QWidget>
class QMenu;
class QPushButton;

namespace Ui {
class FileEncodeMenu;
}

class FileEncodeMenu : public QWidget
{
    Q_OBJECT

public:
    explicit FileEncodeMenu(QWidget *parent = nullptr);
    ~FileEncodeMenu();
signals:
    void sigChangeFileEncode(QString encode);
public slots:
    void OnSetEncodeName(QString name);
private:
    void initFileEncodes();
private:
    Ui::FileEncodeMenu *ui;
    QMenu *m_pMenu = nullptr;
    QPushButton *m_pBtn = nullptr;
    static QMap<QString,QStringList> m_groupEncodeMap;
};

#endif // FILEENCODEMENU_H
