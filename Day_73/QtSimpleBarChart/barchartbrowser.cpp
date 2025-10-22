#include "barchartbrowser.h"
#include "ui_barchartbrowser.h"

BarChartBrowser::BarChartBrowser(QWidget *parent)
    : QMainWindow(parent)
    , ui(new Ui::BarChartBrowser)
{
    ui->setupUi(this);
}

BarChartBrowser::~BarChartBrowser()
{
    delete ui;
}

void BarChartBrowser::on_actionLoad_Data_triggered()
{
    /*
      QBarSeries class -> Vertical Bar Series
      QHorizontalBarSeries Class -> Horizontal Bar Series ;
      QBarset class -> The QBarSet class represents one set of bars
      in a bar chart
    */



    /* // note ::  before initialize series
    if(series != nullptr)
    {
        delete series;
    }
    */

    series = new QBarSeries();   // Vertical Bar Series
    series->setName("Simple Vertical Bar Chart");
    series->setLabelsVisible(true);

    QBarSet *m_set = new QBarSet("BARSET_0");
    m_set->append(1);
    m_set->append(2);
    m_set->append(3);
    m_set->append(4);
    m_set->append(5);
    m_set->append(6);
    series->append(m_set);


    QBarSet *m_set1 = new QBarSet("BARSET_1");
    *m_set1 << 3 << 5 << 8 << 13 << 8 << 5;
    series->append(m_set1);

    QString statMsg = "Series Count : " + QString::number(series->count());
    statMsg +="{";
    for ( int i =0 ; i < series->count(); i++)
    {
        statMsg += " (";
        QBarSet *currSets = series->barSets().at(i);
        for ( int j=0 ; j < currSets->count() ; j++)
        {
            statMsg += QString::number(currSets->at(j)) + ",";
            if( maxRange < currSets->at(j) )
            {
                maxRange = currSets->at(j);
            }
        }
        statMsg += ")";
    }
    statMsg +=" }";
    this->statusBar()->showMessage(statMsg);

}


void BarChartBrowser::on_actionShow_Chart_triggered()
{
    QChart *chart = new QChart();
    chart->legend()->hide();
    chart->addSeries(series);


    QStringList categories;
    for(int i =0 ; i < series->barSets().at(0)->count(); i++)
    {
        categories.append("BAR"+QString::number(i));
    }
    QBarCategoryAxis *axisX = new QBarCategoryAxis();
    axisX->append(categories);
    chart->addAxis(axisX,Qt::AlignBottom);
    series->attachAxis(axisX);

    QValueAxis *axisY = new QValueAxis();
    maxRange = int(maxRange) + 1;
    axisY->setRange(0,maxRange);
    chart->addAxis(axisY,Qt::AlignLeft);
    series->attachAxis(axisY);


    QFont cFont = chart->titleFont();
    cFont.setPointSize(12);
    cFont.setBold(true);
    cFont.setItalic(true);
    chart->setTitleFont(cFont);
    chart->setTitle(series->name());

    QChartView *chartView = new QChartView(chart);
    chartView->setRenderHint(QPainter::Antialiasing);
    this->setCentralWidget(chartView);
}

