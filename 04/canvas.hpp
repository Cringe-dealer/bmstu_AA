#ifndef CANVAS_H
#define CANVAS_H

#include <QWidget>
#include <QColor>
#include <QPainter>
#include <stdio.h>
#include <vector>
#include <stdlib.h>
#include <QMouseEvent>
#include <QKeyEvent>

#include "polygon.hpp"

class canvas : public QWidget
{
    Q_OBJECT

public:
    explicit canvas(QWidget *parent = nullptr);
    ~canvas();
    void paintEvent(QPaintEvent *event);
    void mousePressEvent(QMouseEvent *event);
    void finish_figure();
    void add_hole();

    void get_time(double &time, size_t th_count, polygon *pol);

    void clear();

    void set_bg(const QColor &color);
    void set_fg(const QColor &color);
    void set_paint_col(const QColor &color);

    void set_hor();
    void set_ver();

    void add_point(int x, int y);

private:
    void redraw();
    QImage *image = nullptr;

    std::vector<polygon *> shapes;

    QColor bg;
    QColor fg;
    QColor paint_col;

    bool finished = true;
    bool horizontal = false;
    bool vertical = false;
};

#endif // CANVAS_H
