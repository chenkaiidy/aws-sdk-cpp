﻿/*
* Copyright 2010-2017 Amazon.com, Inc. or its affiliates. All Rights Reserved.
*
* Licensed under the Apache License, Version 2.0 (the "License").
* You may not use this file except in compliance with the License.
* A copy of the License is located at
*
*  http://aws.amazon.com/apache2.0
*
* or in the "license" file accompanying this file. This file is distributed
* on an "AS IS" BASIS, WITHOUT WARRANTIES OR CONDITIONS OF ANY KIND, either
* express or implied. See the License for the specific language governing
* permissions and limitations under the License.
*/

#include <aws/ec2/model/OnDemandOptionsRequest.h>
#include <aws/core/utils/xml/XmlSerializer.h>
#include <aws/core/utils/StringUtils.h>
#include <aws/core/utils/memory/stl/AWSStringStream.h>

#include <utility>

using namespace Aws::Utils::Xml;
using namespace Aws::Utils;

namespace Aws
{
namespace EC2
{
namespace Model
{

OnDemandOptionsRequest::OnDemandOptionsRequest() : 
    m_allocationStrategy(FleetOnDemandAllocationStrategy::NOT_SET),
    m_allocationStrategyHasBeenSet(false),
    m_singleInstanceType(false),
    m_singleInstanceTypeHasBeenSet(false),
    m_minTargetCapacity(0),
    m_minTargetCapacityHasBeenSet(false)
{
}

OnDemandOptionsRequest::OnDemandOptionsRequest(const XmlNode& xmlNode) : 
    m_allocationStrategy(FleetOnDemandAllocationStrategy::NOT_SET),
    m_allocationStrategyHasBeenSet(false),
    m_singleInstanceType(false),
    m_singleInstanceTypeHasBeenSet(false),
    m_minTargetCapacity(0),
    m_minTargetCapacityHasBeenSet(false)
{
  *this = xmlNode;
}

OnDemandOptionsRequest& OnDemandOptionsRequest::operator =(const XmlNode& xmlNode)
{
  XmlNode resultNode = xmlNode;

  if(!resultNode.IsNull())
  {
    XmlNode allocationStrategyNode = resultNode.FirstChild("AllocationStrategy");
    if(!allocationStrategyNode.IsNull())
    {
      m_allocationStrategy = FleetOnDemandAllocationStrategyMapper::GetFleetOnDemandAllocationStrategyForName(StringUtils::Trim(allocationStrategyNode.GetText().c_str()).c_str());
      m_allocationStrategyHasBeenSet = true;
    }
    XmlNode singleInstanceTypeNode = resultNode.FirstChild("SingleInstanceType");
    if(!singleInstanceTypeNode.IsNull())
    {
      m_singleInstanceType = StringUtils::ConvertToBool(StringUtils::Trim(singleInstanceTypeNode.GetText().c_str()).c_str());
      m_singleInstanceTypeHasBeenSet = true;
    }
    XmlNode minTargetCapacityNode = resultNode.FirstChild("MinTargetCapacity");
    if(!minTargetCapacityNode.IsNull())
    {
      m_minTargetCapacity = StringUtils::ConvertToInt32(StringUtils::Trim(minTargetCapacityNode.GetText().c_str()).c_str());
      m_minTargetCapacityHasBeenSet = true;
    }
  }

  return *this;
}

void OnDemandOptionsRequest::OutputToStream(Aws::OStream& oStream, const char* location, unsigned index, const char* locationValue) const
{
  if(m_allocationStrategyHasBeenSet)
  {
      oStream << location << index << locationValue << ".AllocationStrategy=" << FleetOnDemandAllocationStrategyMapper::GetNameForFleetOnDemandAllocationStrategy(m_allocationStrategy) << "&";
  }

  if(m_singleInstanceTypeHasBeenSet)
  {
      oStream << location << index << locationValue << ".SingleInstanceType=" << std::boolalpha << m_singleInstanceType << "&";
  }

  if(m_minTargetCapacityHasBeenSet)
  {
      oStream << location << index << locationValue << ".MinTargetCapacity=" << m_minTargetCapacity << "&";
  }

}

void OnDemandOptionsRequest::OutputToStream(Aws::OStream& oStream, const char* location) const
{
  if(m_allocationStrategyHasBeenSet)
  {
      oStream << location << ".AllocationStrategy=" << FleetOnDemandAllocationStrategyMapper::GetNameForFleetOnDemandAllocationStrategy(m_allocationStrategy) << "&";
  }
  if(m_singleInstanceTypeHasBeenSet)
  {
      oStream << location << ".SingleInstanceType=" << std::boolalpha << m_singleInstanceType << "&";
  }
  if(m_minTargetCapacityHasBeenSet)
  {
      oStream << location << ".MinTargetCapacity=" << m_minTargetCapacity << "&";
  }
}

} // namespace Model
} // namespace EC2
} // namespace Aws
