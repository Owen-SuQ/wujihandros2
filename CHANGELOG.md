# Changelog

All notable changes to this project will be documented in this file.

The format is based on [Keep a Changelog](https://keepachangelog.com/en/1.1.0/),
and this project adheres to [Semantic Versioning](https://semver.org/spec/v2.0.0.html).

## [Unreleased]

### Fixed

- Upgrade wujihandcpp SDK to v1.4.0
- Fix RViz display and parameter issues
- Force serial_number to string type for ROS2 Kilted compatibility

### Changed

- Rename organization from Wuji-Technology-Co-Ltd to wuji-technology

## [0.1.0] - 2025-12-19

### Added

- Multi-hand namespace support with XACRO for running multiple hands simultaneously
- Adapt driver to wujihandcpp SDK 1.4.0
- CI build status badge in README
- Separate xacro files for left and right hand models

### Fixed

- Auto-detect handedness from hardware instead of manual configuration
- Correct handedness mapping (0=right, 1=left)
- Rename deb package to ros-{distro}-wujihand
- Fix release.yml workflow and clean up repository

### Changed

- Use ROS logging API and improve error handling in launch files
- Extract spawn_robot_state_publisher to common.py
- Remove hand_type parameter, use auto-detect only
- Update README structure and installation instructions

### Removed

- Simulation-related code and documentation

[Unreleased]: https://github.com/wuji-technology/wujihandros2/compare/v0.1.0...HEAD
[0.1.0]: https://github.com/wuji-technology/wujihandros2/releases/tag/v0.1.0
