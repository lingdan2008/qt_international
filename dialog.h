#ifndef DIALOG_H
#define DIALOG_H

#include <QDialog>

namespace Ui {
class Dialog;
}

class Dialog : public QDialog
{
    Q_OBJECT

public:
    explicit Dialog(QWidget *parent = 0);
    ~Dialog();

    void changeEvent(QEvent *e);
    void RefreshUI(bool bEnglish);

public slots:
    void OnClickButtonEnglish();
    void OnClickButtonChinese();

private:
    Ui::Dialog *ui;
};

#endif // DIALOG_H
