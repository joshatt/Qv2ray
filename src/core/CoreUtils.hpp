﻿#pragma once
#include "base/models/CoreObjectModels.hpp"
#include "base/models/QvSafeType.hpp"
#include "core/CoreSafeTypes.hpp"

#include <QString>

namespace Qv2ray::core
{
    const inline GroupId DefaultGroupId = GroupId("000000000000");
    using namespace Qv2ray::base;
    using namespace Qv2ray::base::safetype;
    using namespace Qv2ray::base::objects;
    //
    inline const QString getTag(const INBOUND &in)
    {
        return in["tag"].toString();
    }

    inline const QString getTag(const OUTBOUND &in)
    {
        return in["tag"].toString();
    }

    inline const QString getTag(const RuleObject &in)
    {
        return in.QV2RAY_RULE_TAG;
    }
    //
    int64_t GetConnectionLatency(const ConnectionId &id);
    uint64_t GetConnectionTotalData(const ConnectionId &id);
    const tuple<quint64, quint64> GetConnectionUsageAmount(const ConnectionId &id);
    //
    const tuple<QString, QString, int> GetConnectionInfo(const ConnectionId &id, bool *status = nullptr);
    const tuple<QString, QString, int> GetConnectionInfo(const CONFIGROOT &out, bool *status = nullptr);
    //
    bool GetOutboundInfo(const OUTBOUND &out, QString *host, int *port, QString *protocol);
    bool IsComplexConfig(const CONFIGROOT &root);
    bool IsComplexConfig(const ConnectionId &id);
    //
    const QString GetConnectionProtocolString(const ConnectionId &id);
    //
    const QString GetDisplayName(const ConnectionId &id, int limit = -1);
    const QString GetDisplayName(const GroupId &id, int limit = -1);
    //
    const GroupId GetConnectionGroupId(const ConnectionId &id);
    //
    const QMap<QString, int> GetConfigInboundPorts(const CONFIGROOT &root);
    const QMap<QString, int> GetConfigInboundPorts(const ConnectionId &id);
    //
} // namespace Qv2ray::core

using namespace Qv2ray::core;
