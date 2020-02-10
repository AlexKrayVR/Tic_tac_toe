#include "modelboard.h"

ModelBoard::ModelBoard():m_board(vector<vector<QChar>>(row, vector<QChar>(column, ' ')))
{




}

QHash<int, QByteArray> ModelBoard::roleNames() const
{
    QHash<int, QByteArray> role = QAbstractTableModel::roleNames();

    role[Field] = "field";
    return role;
}

int ModelBoard::rowCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return row;
}

int ModelBoard::columnCount(const QModelIndex &parent) const
{
    if (parent.isValid())
        return 0;

    return column;
}
QVariant ModelBoard::data(const QModelIndex &index, int role) const
{
    if (!index.isValid() || role != Field)
        return QVariant();

    return QVariant(m_board[index.column()][index.row()]);

}

void ModelBoard::setChar(int ch,int index )
{
    beginResetModel();

    m_board[1][1] = ch;

    endResetModel();

}

void ModelBoard::check()
{

    char n1 = 'X';
    char n2 = 'O';
    QString msg="";

    if ((m_board[0][0]!=' ')&&(m_board[0][0] == m_board[1][1]) && (m_board[0][0] == m_board[2][2]) ) {
        if (m_board[0][0]== n1)
        {
            qDebug()<<"Player1 WON" << endl;
            emit sendToQML(QString("Player1 WON"));
            return;
        }
        else
        {
            qDebug()<< "Player2 WON" << endl;
            emit sendToQML(QString("Player2 WON"));
            return;
        }
    }
    if ((m_board[0][2]!=' ')&&(m_board[0][2] == m_board[1][1]) && (m_board[0][2] == m_board[2][0]) ) {
        if (m_board[0][2] == n1)
        {
           qDebug()<<"Player1 WON" << endl;
           emit sendToQML(QString("Player1 WON"));
           return;
        }
        else
        {
            qDebug()<<"Player2 WON" << endl;
            emit sendToQML(QString("Player2 WON"));
            return;
        }
    }
    if ((m_board[0][0]!=' ')&&(m_board[0][0] == m_board[0][1]) && (m_board[0][0] == m_board[0][2])) {
        if (m_board[0][0] == n1)
        {
           qDebug()<< "Player1 WON" << endl;
           emit sendToQML(QString("Player1 WON"));
           return;
        }
        else
        {
            qDebug()<< "Player2 WON" << endl;
            emit sendToQML(QString("Player2 WON"));
            return;
        }
    }
    if ((m_board[1][0]!=' ')&&(m_board[1][0] == m_board[1][1]) && (m_board[1][0] == m_board[1][2])) {
        if (m_board[1][0] == n1)
        {
           qDebug()<< "Player1 WON" << endl;
           emit sendToQML(QString("Player1 WON"));
           return;
        }
        else
        {
            qDebug()<< "Player2 WON" << endl;
            emit sendToQML(QString("Player2 WON"));
            return;
        }
    }
    if ((m_board[2][0]!=' ')&&(m_board[2][0] == m_board[2][1]) && (m_board[2][0] == m_board[2][2])) {
        if (m_board[2][0] == n1)
        {
            qDebug()<< "Player1 WON" << endl;
            emit sendToQML(QString("Player1 WON"));
            return;
        }
        else
        {
            qDebug()<< "Player2 WON" << endl;
            emit sendToQML(QString("Player2 WON"));
            return;
        }
    }
    if ((m_board[0][0]!=' ')&&(m_board[0][0] == m_board[1][0]) && (m_board[0][0] == m_board[2][0])) {
        if (m_board[0][0] == n1)
        {
            qDebug()<< "Player1 WON" << endl;
            emit sendToQML(QString("Player1 WON"));
            return;
        }
        else
        {
            qDebug()<< "Player2 WON" << endl;
            emit sendToQML(QString("Player2 WON"));
            return;
        }
    }
    if ((m_board[0][1]!=' ')&&(m_board[0][1] == m_board[1][1]) && (m_board[0][1] == m_board[2][1])) {
        if (m_board[0][1] == n1)
        {
           qDebug()<< "Player1 WON" << endl;
           emit sendToQML(QString("Player1 WON"));
           return;

        }
        else
        {
           qDebug()<< "Player2 WON" << endl;
           emit sendToQML(QString("Player2 WON"));
           return;
        }
    }
    if ((m_board[0][2]!=' ')&&(m_board[0][2] == m_board[1][2]) && (m_board[0][2] == m_board[2][2])) {
        if (m_board[0][2] == n1)
        {
            qDebug()<<"Player1 WON" << endl;
            emit sendToQML(QString("Player1 WON"));
            return;
        }
        else
        {
            qDebug()<< "Player2 WON" << endl;
            emit sendToQML(QString("Player2 WON"));
            return;
        }
    }






}

void ModelBoard::clean()
{
    for (auto &el : m_board)
    {
        for (auto &n : el) {
            n=' ';
        }
    }
}

bool ModelBoard::setData(const QModelIndex &index, const QVariant &value, int role)
{
    if (role != Field || data(index, role) == value)
        return false;
    if (m_board[index.column()][index.row()]=='X' || m_board[index.column()][index.row()]=='O'){
        return false;
    }else {
        m_board[index.column()][index.row()] = value.toChar();
    }
    emit dataChanged(index, index);
    return true;
}
