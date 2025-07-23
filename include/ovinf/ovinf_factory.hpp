#ifndef OVINF_FACTORY_HPP
#define OVINF_FACTORY_HPP

#include "ovinf.hpp"
#include "ovinf_humanoid.h"
#include "ovinf_humanoid_stand.h"
#include "ovinf_humanoid_walk.h"
#include "ovinf_humanoid_walk_clock.h"

namespace ovinf {

class PolicyFactory {
 public:
  template <typename T = float>
  static std::shared_ptr<ovinf::BasePolicy<T>> CreatePolicy(
      YAML::Node const &config) {
    std::string policy_type = config["policy_type"].as<std::string>();
    if (policy_type == "Humanoid") {
      return std::make_shared<HumanoidPolicy>(config);
    } else if (policy_type == "HumanoidStand") {
      return std::make_shared<HumanoidStandPolicy>(config);
    } else if (policy_type == "HumanoidWalk") {
      return std::make_shared<HumanoidWalkPolicy>(config);
    } else if (policy_type == "HumanoidWalkClock") {
      return std::make_shared<HumanoidWalkClockPolicy>(config);
    } else {
      throw std::invalid_argument("Unknown policy type: " + policy_type);
    }
  }
};

}  // namespace ovinf
#endif  // !OVINF_FACTORY_HPP
