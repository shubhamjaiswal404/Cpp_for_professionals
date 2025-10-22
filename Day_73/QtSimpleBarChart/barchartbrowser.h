#ifndef BARCHARTBROWSER_H
#define BARCHARTBROWSER_H

#include <QMainWindow>
#include <QMessageBox>
#include <QFont>

#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QBarSeries>
#include <QtCharts/QHorizontalBarSeries>
#include <QtCharts/QBarSet>
#include <QtCharts/QBarCategoryAxis>
#include <QtCharts/QValueAxis>


QT_BEGIN_NAMESPACE
namespace Ui {
class BarChartBrowser;
}
QT_END_NAMESPACE

class BarChartBrowser : public QMainWindow
{
    Q_OBJECT

public:
    BarChartBrowser(QWidget *parent = nullptr);
    ~BarChartBrowser();

private slots:
    void on_actionLoad_Data_triggered();

    void on_actionShow_Chart_triggered();

private:
    int maxRange;
    QBarSeries *series;
    Ui::BarChartBrowser *ui;
};
#endif // BARCHARTBROWSER_H
