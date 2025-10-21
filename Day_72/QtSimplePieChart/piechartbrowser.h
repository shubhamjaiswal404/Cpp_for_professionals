#ifndef PIECHARTBROWSER_H
#define PIECHARTBROWSER_H

#include <QMainWindow>
#include <QMessageBox>
#include <QtCharts/QChart>
#include <QtCharts/QChartView>
#include <QtCharts/QPieSeries>
#include <QtCharts/QPieSlice>
#include <QList>
#include <QFont>


QT_BEGIN_NAMESPACE
namespace Ui {
class PieChartBrowser;
}
QT_END_NAMESPACE

class PieChartBrowser : public QMainWindow
{
    Q_OBJECT

public:
    PieChartBrowser(QWidget *parent = nullptr);
    ~PieChartBrowser();

private slots:
    void on_actionLoad_Data_triggered();

    void on_actionShow_Chart_triggered();

private:
    QPieSeries *series;
    Ui::PieChartBrowser *ui;
};
#endif // PIECHARTBROWSER_H
