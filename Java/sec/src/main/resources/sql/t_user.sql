/*
 Navicat MySQL Data Transfer

 Source Server         : localhost_3306
 Source Server Type    : MySQL
 Source Server Version : 80028
 Source Host           : localhost:3306
 Source Schema         : study_1

 Target Server Type    : MySQL
 Target Server Version : 80028
 File Encoding         : 65001

 Date: 28/06/2022 14:55:55
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for t_user
-- ----------------------------
DROP TABLE IF EXISTS `t_user`;
CREATE TABLE `t_user`  (
  `id` int NOT NULL,
  `username` varchar(30) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `password` varchar(200) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `age` int NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of t_user
-- ----------------------------
INSERT INTO `t_user` VALUES (1, 'Mike', '$2a$10$C/QvgmtzZwQowQbI0Glm2eynrw5VRXHbDKkcaKSqxEIQkcYBpFRBK', 23);
INSERT INTO `t_user` VALUES (2, 'Jack', '$2a$10$C/QvgmtzZwQowQbI0Glm2eynrw5VRXHbDKkcaKSqxEIQkcYBpFRBK', 23);
INSERT INTO `t_user` VALUES (3, 'Mary', '$2a$10$C/QvgmtzZwQowQbI0Glm2eynrw5VRXHbDKkcaKSqxEIQkcYBpFRBK', 23);
INSERT INTO `t_user` VALUES (4, 'Rose', '$2a$10$C/QvgmtzZwQowQbI0Glm2eynrw5VRXHbDKkcaKSqxEIQkcYBpFRBK', 22);
INSERT INTO `t_user` VALUES (5, 'Allen', '$2a$10$C/QvgmtzZwQowQbI0Glm2eynrw5VRXHbDKkcaKSqxEIQkcYBpFRBK', 21);

SET FOREIGN_KEY_CHECKS = 1;
