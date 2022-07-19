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

 Date: 28/06/2022 14:55:25
*/

SET NAMES utf8mb4;
SET FOREIGN_KEY_CHECKS = 0;

-- ----------------------------
-- Table structure for student
-- ----------------------------
DROP TABLE IF EXISTS `student`;
CREATE TABLE `student`  (
  `id` int NOT NULL,
  `name` varchar(20) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  `age` int NULL DEFAULT NULL,
  `classId` int NULL DEFAULT NULL,
  `gender` int NULL DEFAULT NULL,
  `score` int NULL DEFAULT NULL,
  `enroll_date` datetime NULL DEFAULT NULL,
  `photo` varchar(255) CHARACTER SET utf8mb4 COLLATE utf8mb4_0900_ai_ci NULL DEFAULT NULL,
  PRIMARY KEY (`id`) USING BTREE
) ENGINE = InnoDB CHARACTER SET = utf8mb4 COLLATE = utf8mb4_0900_ai_ci ROW_FORMAT = Dynamic;

-- ----------------------------
-- Records of student
-- ----------------------------
INSERT INTO `student` VALUES (1001, 'QQ', 19, 1, 3, 70, '2022-05-20 10:54:02', '20220520110715652.jpg');
INSERT INTO `student` VALUES (1002, 'PDD', 20, 3, 3, 80, '2022-05-20 10:54:07', '20220520110912541.jpg');
INSERT INTO `student` VALUES (1003, 'TaoBao', 20, 2, 3, 85, '2022-05-20 10:54:11', '20220520111053752.jpg');
INSERT INTO `student` VALUES (1004, 'AAAA', 25, 1, 3, 79, '2022-05-20 10:54:19', NULL);
INSERT INTO `student` VALUES (1005, 'adcass', 16, 2, 4, 55, '2022-05-20 10:54:21', NULL);
INSERT INTO `student` VALUES (1006, 'Arcana', 23, 5, 4, 59, '2022-05-20 10:54:23', NULL);
INSERT INTO `student` VALUES (1007, 'Argent', 22, 5, 4, 61, '2022-05-20 10:54:25', NULL);
INSERT INTO `student` VALUES (1008, 'Alice', 21, 3, 3, 60, '2022-05-20 10:54:27', NULL);
INSERT INTO `student` VALUES (1009, 'Bill', 15, 4, 4, 88, '2022-05-20 10:54:30', NULL);
INSERT INTO `student` VALUES (1010, 'Bob', 21, 4, 4, 99, '2022-05-20 10:54:32', NULL);

SET FOREIGN_KEY_CHECKS = 1;
