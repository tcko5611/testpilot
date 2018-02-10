#include "ophidform.h"
#include "ui_ophidform.h"

ophidform::ophidform(QWidget *parent) :
    QWidget(parent),
    ui(new Ui::ophidform)
{
    ui->setupUi(this);
}

ophidform::~ophidform()
{
    delete ui;
}
