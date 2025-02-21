#ifndef SCROLLAREAPROPERTIES_H
#define SCROLLAREAPROPERTIES_H

#include <QFormLayout>
#include <QLabel>

class ScrollAreaProperties
{
public:
    QHBoxLayout *CreateQHBoxLayout(QString first_text, int t_width, int t_height, QString style);
    QHBoxLayout *CreateQHBoxLayout(QString first_text, QString second_text, QString third_text, int t_width, int t_height, QString style);
    QHBoxLayout *CreateQHBoxLayout(QString first_text, QString second_text, QString third_text, QString fourth_text, QString fifth_text,
                                   int t_width, int t_height, QString style);
    QLabel *CreateQLabel(QString text, int t_width, int t_height, QString style);
};

#endif // SCROLLAREAPROPERTIES_H
