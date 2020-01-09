#include "dialog.h"
#include "ui_dialog.h"
#include <QDebug>
#include <QTranslator>

Dialog::Dialog(QWidget *parent) :
    QDialog(parent),
    ui(new Ui::Dialog)
{
    ui->setupUi(this);

    connect(ui->pushButton_English, SIGNAL(clicked(bool)), this, SLOT(OnClickButtonEnglish()));
    connect(ui->pushButton_Chinese, SIGNAL(clicked(bool)), this, SLOT(OnClickButtonChinese()));

    RefreshUI(true);
}

Dialog::~Dialog()
{
    delete ui;
}

void Dialog::OnClickButtonEnglish()
{
    RefreshUI(true);

    qDebug() << "OnClickButtonEnglish";
}

void Dialog::OnClickButtonChinese()
{
    RefreshUI(false);

    qDebug() << "OnClickButtonChinese";
}

void Dialog::changeEvent(QEvent *e)
{
    QDialog::changeEvent(e);
    switch (e->type()) {
    case QEvent::LanguageChange:
        ui->retranslateUi(this);
        break;
    default:
        break;
    }

    qDebug() << "changeEvent";
}

void Dialog::RefreshUI(bool bEnglish)
{
    static QTranslator *pTrans;

    if(NULL != pTrans) {
        qApp->removeTranslator(pTrans);
        delete pTrans;
        pTrans = NULL;
    }
    pTrans = new QTranslator();

    if(bEnglish) {
        pTrans->load(QObject::tr("en_CN.qm"));
    }
    else {
        pTrans->load(QObject::tr("zh_CN.qm"));
    }

    qApp->installTranslator(pTrans);

    qDebug() << "RefreshUI" << bEnglish;
}
