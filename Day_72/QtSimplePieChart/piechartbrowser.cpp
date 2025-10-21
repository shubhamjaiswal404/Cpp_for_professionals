#include "piechartbrowser.h"
#include "ui_piechartbrowser.h"

PieChartBrowser::PieChartBrowser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::PieChartBrowser)
{
    ui->setupUi(this);
}

PieChartBrowser::~PieChartBrowser()
{
    delete ui;
}

void PieChartBrowser::on_actionLoad_Data_triggered()
{
    series = new QPieSeries();
    series->setName("MyChart");

    series->append("S0:30", 30);
    series->append("S1:25", 25);
    series->append("S2:20", 20);
    series->append("S3:15", 15);

    // series->append("S4:10 ,10);
    QPieSlice *slice = new QPieSlice();
    slice->setLabel("S4:10");
    slice->setValue(10);
    series->append(std::move(slice));

    for ( int i = 0 ; i < series->count() ; i++)
    {
        series->slices().at(i)->setLabelVisible(true);

        if( i== 0)
        {
            series->slices().at(i)->setLabelPosition(
                QPieSlice::LabelInsideNormal);
        }
        else if( i == 1)
        {
            series->slices().at(i)->setColor(Qt::yellow);
            series->slices().at(i)->setLabelPosition(
                QPieSlice::LabelInsideHorizontal);
        }
        else if( i == 2)
        {
            series->slices().at(i)->setLabelPosition(
                QPieSlice::LabelInsideTangential);
        }
        else if( i == 3)
        {
            series->slices().at(i)->setLabelPosition(
                QPieSlice::LabelOutside);
            QFont m_font = series->slices().at(i)->labelFont();
            m_font.setPointSize(12);
            m_font.setBold(true);
            m_font.setItalic(true);
            series->slices().at(i)->setLabelFont(m_font);
        }
        else
        {

            // Empty
        }
    }

    series->setPieSize(0.7);


}


void PieChartBrowser::on_actionShow_Chart_triggered()
{
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);
    chart->setTitle("My TEST pie Chart");

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    this->setCentralWidget(chartView);
}

