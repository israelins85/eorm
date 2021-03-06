/****************************************************************************
**
** Copyright (C) 2013 Victor Zhuk.
** Contact: chewire@gmail.com
**
** This file is part of the EOrm library.
**
** $QT_BEGIN_LICENSE:BSD$
** You may use this file under the terms of the BSD license as follows:
**
** "Redistribution and use in source and binary forms, with or without
** modification, are permitted provided that the following conditions are
** met:
**
**  * Redistributions of source code must retain the above copyright notice,
**    this list of conditions and the following disclaimer.
**
**  * Redistributions in binary form must reproduce the above copyright
**    notice, this list of conditions and the following disclaimer in the
**    documentation and/or other materials provided with the distribution.
**
**  * Neither the name of the project's author nor the names of its
**    contributors may be used to endorse or promote products derived from
**    this software without specific prior written permission.
**
** THIS SOFTWARE IS PROVIDED BY THE COPYRIGHT HOLDERS AND CONTRIBUTORS
** "AS IS" AND ANY EXPRESS OR IMPLIED WARRANTIES, INCLUDING, BUT NOT
** LIMITED TO, THE IMPLIED WARRANTIES OF MERCHANTABILITY AND FITNESS FOR
** A PARTICULAR PURPOSE ARE DISCLAIMED. IN NO EVENT SHALL THE COPYRIGHT
** OWNER OR CONTRIBUTORS BE LIABLE FOR ANY DIRECT, INDIRECT, INCIDENTAL,
** SPECIAL, EXEMPLARY, OR CONSEQUENTIAL DAMAGES (INCLUDING, BUT NOT
** LIMITED TO, PROCUREMENT OF SUBSTITUTE GOODS OR SERVICES; LOSS OF USE,
** DATA, OR PROFITS; OR BUSINESS INTERRUPTION) HOWEVER CAUSED AND ON ANY
** THEORY OF LIABILITY, WHETHER IN CONTRACT, STRICT LIABILITY, OR TORT
** (INCLUDING NEGLIGENCE OR OTHERWISE) ARISING IN ANY WAY OUT OF THE USE
** OF THIS SOFTWARE, EVEN IF ADVISED OF THE POSSIBILITY OF SUCH DAMAGE."
**
** $QT_END_LICENSE$
**
****************************************************************************/

#ifndef EORM_H
#define EORM_H

#include "eorm_global.h"
#include <QObject>
#include <QtSql>
#include "eormexception.h"

/*!
 * \class EOrm
 *
 * \lang_en
 * \brief The Static class which is carry out various help functions, and
 *  also gave the mechanism of errors processing.
 * \endlang
 *
 * \lang_ru
 * \brief Статический класс, выполняющий различные вспомогательные функции, а
 *  также предоставляющий механизм обработки ошибок.
 * \endlang
 */
class EORMSHARED_EXPORT EOrm : QObject
{
    Q_OBJECT

public:
    enum ErrorType { Exceptions, ErrorCodes };
    static QSqlDatabase activeConnection();
    static QString connectionName();
    static void setConnectionName(QString connectionName);
    static void throwError(uint code,
                           QString message = QString("Unknown error."));

private:
    static ErrorType m_errorType;
    static int m_errorCode;
    static QString m_errorMessage;
    static QString m_connectionName;

};

#endif // EORM_H
