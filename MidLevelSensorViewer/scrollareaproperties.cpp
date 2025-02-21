#include "scrollareaproperties.h"

QHBoxLayout *ScrollAreaProperties::CreateQHBoxLayout(QString first_text, int t_width, int t_height, QString style)
{
    QHBoxLayout *hbox_layout = new QHBoxLayout();
    QLabel *label = CreateQLabel(first_text, t_width, t_height, style);
    hbox_layout->setContentsMargins(0, 0, 0, 0);
    hbox_layout->setSpacing(0);
    hbox_layout->addWidget(label);

    return hbox_layout;
}

QHBoxLayout *ScrollAreaProperties::CreateQHBoxLayout(QString first_text, QString second_text, QString third_text, int t_width, int t_height, QString style)
{
    QHBoxLayout *hbox_layout = new QHBoxLayout();
    QLabel *label_1 = CreateQLabel(first_text, t_width, t_height, style);
    QLabel *label_2 = CreateQLabel(second_text, t_width, t_height, style);
    QLabel *label_3 = CreateQLabel(third_text, t_width, t_height, style);

    hbox_layout->setContentsMargins(0, 0, 0, 0);
    hbox_layout->setSpacing(0);
    hbox_layout->addWidget(label_1);
    hbox_layout->addWidget(label_2);
    hbox_layout->addWidget(label_3);

    return hbox_layout;
}

QHBoxLayout *ScrollAreaProperties::CreateQHBoxLayout(QString first_text, QString second_text, QString third_text, QString fourth_text, QString fifth_text,
                                                     int t_width, int t_height, QString style)
{
    QHBoxLayout *hbox_layout = new QHBoxLayout();
    QLabel *label_1 = CreateQLabel(first_text, t_width, t_height, style);
    QLabel *label_2 = CreateQLabel(second_text, t_width, t_height, style);
    QLabel *label_3 = CreateQLabel(third_text, t_width, t_height, style);
    QLabel *label_4 = CreateQLabel(fourth_text, t_width, t_height, style);
    QLabel *label_5 = CreateQLabel(fifth_text, t_width, t_height, style);

    hbox_layout->setContentsMargins(0, 0, 0, 0);
    hbox_layout->setSpacing(0);
    hbox_layout->addWidget(label_1);
    hbox_layout->addWidget(label_2);
    hbox_layout->addWidget(label_3);
    hbox_layout->addWidget(label_4);
    hbox_layout->addWidget(label_5);

    return hbox_layout;
}

QLabel *ScrollAreaProperties::CreateQLabel(QString text, int t_width, int t_height, QString style)
{
    QLabel *label = new QLabel();
    label->setFixedWidth(t_width);
    label->setFixedHeight(t_height);
    label->setContentsMargins(0, 0, 0, 0);
    label->setStyleSheet(style);
    label->setText(text);

    return label;
}
