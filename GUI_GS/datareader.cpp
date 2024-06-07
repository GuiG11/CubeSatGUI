#include "datareader.h"
#include <QFile>
#include <QTextStream>
#include <QVector>

DataReader::DataReader(const QString &filePath)
    : m_filePath(filePath) {
}

bool DataReader::readFile() {
    QFile file(m_filePath);
    if (!file.open(QIODevice::ReadOnly | QIODevice::Text))
        return false;

    m_values.clear();
    QTextStream in(&file);
    while (!in.atEnd()) {
        QString line = in.readLine();
        QStringList stringValues = line.split(",");
        QVector<double> values;
        for (const QString &str : stringValues) {
            values.append(str.toDouble());
        }
        m_values.append(values);
    }
    return true;
}

QVector<double> DataReader::getValues(int index) const {
    if (index < 0 || index >= m_values.size()) {
        return QVector<double>();
    }
    return m_values[index];
}
