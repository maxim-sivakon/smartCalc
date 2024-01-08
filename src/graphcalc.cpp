#include "graphcalc.h"
#include "ui_graphcalc.h"

graphcalc::graphcalc(QWidget *parent)
    : QDialog(parent)
    , ui(new Ui::graphcalc)
{
    ui->setupUi(this);

    setValidators();

    connect(ui->btn_draw_graph, SIGNAL(clicked()), this, SLOT(drawGraph()));
}

graphcalc::~graphcalc()
{
    delete ui;
}

void graphcalc::drawGraph(){

    ui->widget_graph->clearGraphs();

    int xMin = ui->input_min_x->text().toInt();
    int xMax = ui->input_max_x->text().toInt();
    int yMin = ui->input_min_y->text().toInt();
    int yMax = ui->input_max_y->text().toInt();

    ui->widget_graph->xAxis->setRange(xMin, xMax);
    ui->widget_graph->yAxis->setRange(yMin, yMax);

    int ratio = 1;
    if ((xMax - xMin) >= 20) {
        ratio = (xMax - xMin) / 10;
    }
    double step = 0.1 * ratio;
}

void graphcalc::setValidators(){
    QIntValidator *xMinValidator = new QIntValidator(-1000000, 1000000);
    QIntValidator *xMaxValidator = new QIntValidator(-1000000, 1000000);
    QIntValidator *yMinValidator = new QIntValidator(-1000000, 1000000);
    QIntValidator *yMaxValidator = new QIntValidator(-1000000, 1000000);

    ui->input_min_x->setValidator(xMinValidator);
    ui->input_max_x->setValidator(xMaxValidator);
    ui->input_min_y->setValidator(yMinValidator);
    ui->input_max_y->setValidator(yMaxValidator);
}
