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

    QString player1="Player 1 WON!";
    QString player2="Player 2 WON!";
    QString Draw="Draw";


    if ((m_board[0][0]!=' ')&&(m_board[0][0] == m_board[1][1]) && (m_board[0][0] == m_board[2][2]) ) {
        if (m_board[0][0]== n1)
        {
            qDebug()<<player1 << endl;
            emit sendToQML(QString(player1));
            return;
        }
        else
        {
            qDebug()<< player2<< endl;
            emit sendToQML(QString(player2));
            return;
        }
    }
    if ((m_board[0][2]!=' ')&&(m_board[0][2] == m_board[1][1]) && (m_board[0][2] == m_board[2][0]) ) {
        if (m_board[0][2] == n1)
        {
            qDebug()<<player1 << endl;
            emit sendToQML(QString(player1));
            return;
        }
        else
        {
            qDebug()<<player2 << endl;
            emit sendToQML(QString(player2));
            return;
        }
    }
    if ((m_board[0][0]!=' ')&&(m_board[0][0] == m_board[0][1]) && (m_board[0][0] == m_board[0][2])) {
        if (m_board[0][0] == n1)
        {
            qDebug()<< player1 << endl;
            emit sendToQML(QString(player1));
            return;
        }
        else
        {
            qDebug()<< player2 << endl;
            emit sendToQML(QString(player2));
            return;
        }
    }
    if ((m_board[1][0]!=' ')&&(m_board[1][0] == m_board[1][1]) && (m_board[1][0] == m_board[1][2])) {
        if (m_board[1][0] == n1)
        {
            qDebug()<< player1 << endl;
            emit sendToQML(QString(player1));
            return;
        }
        else
        {
            qDebug()<< player2 << endl;
            emit sendToQML(QString(player2));
            return;
        }
    }
    if ((m_board[2][0]!=' ')&&(m_board[2][0] == m_board[2][1]) && (m_board[2][0] == m_board[2][2])) {
        if (m_board[2][0] == n1)
        {
            qDebug()<< player1 << endl;
            emit sendToQML(QString(player1));
            return;
        }
        else
        {
            qDebug()<< player2 << endl;
            emit sendToQML(QString(player2));
            return;
        }
    }
    if ((m_board[0][0]!=' ')&&(m_board[0][0] == m_board[1][0]) && (m_board[0][0] == m_board[2][0])) {
        if (m_board[0][0] == n1)
        {
            qDebug()<< player1 << endl;
            emit sendToQML(QString(player1));
            return;
        }
        else
        {
            qDebug()<< player2 << endl;
            emit sendToQML(QString(player2));
            return;
        }
    }
    if ((m_board[0][1]!=' ')&&(m_board[0][1] == m_board[1][1]) && (m_board[0][1] == m_board[2][1])) {
        if (m_board[0][1] == n1)
        {
            qDebug()<< player1 << endl;
            emit sendToQML(QString(player1));
            return;

        }
        else
        {
            qDebug()<< player2 << endl;
            emit sendToQML(QString(player2));
            return;
        }
    }
    if ((m_board[0][2]!=' ')&&(m_board[0][2] == m_board[1][2]) && (m_board[0][2] == m_board[2][2])) {
        if (m_board[0][2] == n1)
        {
            qDebug()<<player1 << endl;
            emit sendToQML(QString(player1));
            return;
        }
        else
        {
            qDebug()<< player2 << endl;
            emit sendToQML(QString(player2));
            return;
        }
    }

    //check if everything is full and no one won
    short countFill=0;
    for (auto &el : m_board)
    {
        for (auto &n : el) {
            if(n==' '){
                return;
            }else{
                countFill++;
            }
        }
        if(countFill==9){
         emit sendToQML(QString(Draw));
        }
    }
}

void ModelBoard::clean()
{
    beginResetModel();

    for (auto &el : m_board)
    {
        for (auto &n : el) {
            n=' ';
        }
    }
    endResetModel();
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
