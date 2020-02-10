#ifndef MODELBOARD_H
#define MODELBOARD_H

#include <QObject>
#include<QAbstractTableModel>
#include<vector>
#include<string>
#include<QDebug>
using namespace std;

class ModelBoard : public QAbstractTableModel
{
    Q_OBJECT
public:
    ModelBoard();

    enum Roles{
        Field=Qt::UserRole+1
    };

    QHash<int,QByteArray> roleNames() const override;
    int rowCount(const QModelIndex& parent)const override;
    int columnCount(const QModelIndex &parent) const override;
    bool setData(const QModelIndex &index, const QVariant &value, int role) override;
    QVariant data(const QModelIndex& index, int role) const override;

    Q_INVOKABLE void setChar(int ch,int index);

    Q_INVOKABLE void check();
signals:
    void sendToQML(const QString &msg);

private:
    vector<vector<QChar>> m_board;
    static const int row=3;
    static const int column=3;

    void clean();

};

#endif // MODELBOARD_H
