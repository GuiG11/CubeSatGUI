#ifndef DATAREADER_H
#define DATAREADER_H

#include <QString>
#include <QVector>

class DataReader {
public:
    DataReader(const QString &filePath);
    bool readFile();
    QVector<double> getValues(int index) const;

private:
    QString m_filePath;
    QVector<QVector<double>> m_values;
};

#endif // DATAREADER_H
