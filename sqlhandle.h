#ifndef SQLHANDLE_H
#define SQLHANDLE_H

#include "SqlHandle_global.h"
#include <QObject>
#include <QtSql>
#include <QDebug>
#include <QSqlError>
#include <QSqlTableModel>
#include <QSqlDatabase>

class SQLHANDLE_EXPORT SqlHandle
{
public:

    SqlHandle();

    enum OperatorLikePlace {Begining, Middle, End};

    static QString CreateTableCommand(QString tableName, QStringList columnNames, QStringList columnTypes
                                      , bool SQLITE = true);

    static QString AddRecordCommand(QString tableName, QStringList columnNames, QStringList columnTypes, QStringList values);

    static QString DeleteRecordCommand(QString tableName, QString primaryName, QString primaryType, QString primaryValue);

    static QString DeleteRecordCommandLikeOperator(QString tableName, QString primaryName, QString primaryType, QString primaryValue, OperatorLikePlace place);

    static QString EditRecordCommand(QString tableName, QString primaryName, QString primaryType, QString primaryValue, QStringList columnNames, QStringList columnTypes, QStringList values);

    static QString EditRecordCommandLikeOperator(QString tableName, QString primaryName, QString primaryType, QString primaryValue, QStringList columnNames, QStringList columnTypes, QStringList values, OperatorLikePlace place);

    static QStringList DropColumnCommandList(QString tableName, QStringList columnNames, QStringList columnTypes
                                         , int unwantedColumn, bool SQLITE = true);


    static QStringList RenameColumnCommandList(QString tableName, QStringList columnNames, QStringList columnTypes
                                               , int consideredColumnNumber, QString newName, bool SQLITE = true);


    static QString AddColumnCommand(QString tableName, QString columnName, QString columnTypes);

    static QString RenameTableCommand(QString oldName, QString newName);

    static QString DropTableCommand(QString tableName);

    static QStringList ReorderTableCommandList(QString tableName, QStringList oldColumnNames,
                                               QStringList oldColumnTypes, QStringList newColumnNames,
                                               QStringList newColumnTypes, bool SQLITE = true);

};

#endif // SQLHANDLE_H
