#include "RadarControlThread.h"
#include "communicate.h"

RadarControlThread::RadarControlThread(void)
    : m_bStartGetData(false)
{
}

void RadarControlThread::action_output_slot(bool output)
{
    std::string t_strCmd;
    if (output)
    {
        t_strCmd = "clioutput 31\r\n";
        comm.writeData(t_strCmd.c_str(), t_strCmd.length());
        m_bStartGetData = true;
        comm.sleep(1);
    }
    else
    {
//        t_strCmd = "clioutput 1\r\n";
//        comm.writeData(t_strCmd.c_str(), t_strCmd.length());
        m_bStartGetData = false;
//        comm.sleep(200);
    }
}

void RadarControlThread::run()
{
    BaseControlThread::run();
    while(!isInterruptionRequested())
    {
        if(m_bStartGetData && comm.isOpen())
        {
            QByteArray result;
            readdatareturn = comm.readAllLines(result, 100);

            if(readdatareturn > 0)
            {
                qDebug() << "readdatareturn: " << readdatareturn;
                QList<QByteArray> data = result.split('\n');
                bool t_bIsHead = true;
                int t_iSize = data.size();
                int t_iIndex = 1;
                for (auto t_strLine : data)
                {
                    m_strLine = t_strLine;
                    if (m_strLine.length() > 0
                        && "Done" != m_strLine)
                    {
                        if (t_bIsHead)
                        {
                            if (m_strLine.startsWith("Ant"))
                            {
                                if (m_strTailData.startsWith("Ant"))
                                {
                                    ParseData(m_strTailData);
                                }
                                ParseData(m_strLine);
                            }
                            else
                            {
                                if (m_strTailData.startsWith("Ant"))
                                {
                                    m_strTailData.append(m_strLine);
                                    ParseData(m_strTailData);
                                }
                            }
                            m_strTailData = "";
                            t_bIsHead = false;
                        }
                        else if (!t_bIsHead && t_iIndex != t_iSize)
                        {
                            ParseData(m_strLine);
                        }

                        if (t_iIndex == t_iSize
                                && m_strLine.startsWith("Ant"))
                        {
                            m_strTailData = m_strLine;
                        }
                        ++t_iIndex;
                    }
                }
            }
        }

        msleep(30);
    }
}

void RadarControlThread::ParseData(QString &t_strLine)
{
//    qDebug() << t_strLine;
    if (!t_strLine.startsWith("Ant"))
    {
        return;
    }

    bool t_bRet = false;

    QString t_strAnt = t_strLine.left(t_strLine.indexOf(','));
    t_strAnt = t_strAnt.mid(3);
    int t_iAnt = t_strAnt.toInt(&t_bRet);

//    QString t_strRangeIdx = t_strLine.mid(t_strLine.indexOf("rangeIdx, ") + 10);
//    t_strRangeIdx = t_strRangeIdx.left(t_strRangeIdx.indexOf(','));
//    int t_iRangeIdx = t_strRangeIdx.toInt(&t_bRet);

    QString t_strPeak = t_strLine.mid(t_strLine.indexOf("Peak:") + 5 );
    int t_iPeak = t_strPeak.toInt(&t_bRet);

//    qDebug() << t_iAnt << ", " << t_iPeak;

    if (t_bRet)
    {
        emit signalDataDeal(t_iAnt, t_iPeak);
    }
}

void RadarControlThread::action_adjust_slot()
{
	//step measureRangeBiasAndRxChanPhase
    QString response = comm.writeDataForResponse("clioutput 0\r\n", 13, "Done", 1000);
    while(!response.contains("Done"))
    {
        response = comm.writeDataForResponse("clioutput 0\r\n", 13, "Done", 1000);
    }
    response = comm.writeDataForResponse("measureRangeBiasAndRxChanPhase 1 6 0.2\r\n", 40, "Done|-", 2000);
	if (response == "Done")
	{
        response = comm.writeDataForResponse("biaojiao\r\n", 10, "operational|Debug", 5000);
		if (response.contains("Done"))
			emit adjust_success();
		else {
			emit adjust_fail(response);
		}
	}
	else {
		emit adjust_fail(response);
	}
}

void RadarControlThread::action_restart_slot()
{
	comm.writeData("softReset\r\n", 11);
}

void RadarControlThread::action_get_uid_slot()
{
    comm.writeData("clioutput 0\r\n", 13);
    comm.sleep(200);
    QString response = comm.writeDataForResponse("sensorGetUID\r\n", 14, "NULL", 1000);
    if(response.contains("Done"))
    {
        emit send_uid(response.mid(response.indexOf("0x"), 9));
    }

    comm.writeData("clioutput 4\r\n", 13);
}
