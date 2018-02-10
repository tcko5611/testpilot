#ifndef OPHIDFORM_H
#define OPHIDFORM_H

#include <QWidget>

namespace Ui {
class ophidform;
}

class ophidform : public QWidget
{
    Q_OBJECT

public:
    explicit ophidform(QWidget *parent = 0);
    ~ophidform();

private:
    Ui::ophidform *ui;
};

#endif // OPHIDFORM_H
