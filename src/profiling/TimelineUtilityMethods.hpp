//
// Copyright © 2019 Arm Ltd. All rights reserved.
// SPDX-License-Identifier: MIT
//

#pragma once

#include "ISendTimelinePacket.hpp"
#include "ProfilingGuid.hpp"

namespace armnn
{

namespace profiling
{

class TimelineUtilityMethods
{
public:
    TimelineUtilityMethods(ISendTimelinePacket& sendTimelinePacket)
        : m_SendTimelinePacket(sendTimelinePacket)
    {}
    ~TimelineUtilityMethods() = default;

    void SendWellKnownLabelsAndEventClasses();

    ProfilingDynamicGuid CreateNamedTypedEntity(const std::string& name, const std::string& type);

    void CreateTypedLabel(ProfilingGuid entityGuid, const std::string& entityName, ProfilingStaticGuid labelTypeGuid);

    ProfilingStaticGuid DeclareLabel(const std::string& labelName);

    void NameEntity(ProfilingGuid entityGuid, const std::string& name);

    void TypeEntity(ProfilingGuid entityGuid, const std::string& type);

private:
    ISendTimelinePacket& m_SendTimelinePacket;
};

} // namespace profiling

} // namespace armnn
