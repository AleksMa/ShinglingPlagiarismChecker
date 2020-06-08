-- CREATE DATABASE docker;
--
-- create user docker with encrypted password 'docker';
--
-- grant all privileges on database docker to docker;

DROP TABLE IF EXISTS users CASCADE;
CREATE TABLE IF NOT EXISTS users
(
    ID        BIGSERIAL NOT NULL PRIMARY KEY,
    userName  TEXT,
    fullName  TEXT,
    studentID TEXT
);

DROP TABLE IF EXISTS tasks CASCADE;
CREATE TABLE IF NOT EXISTS tasks
(
    ID        BIGSERIAL NOT NULL PRIMARY KEY,
    taskName  TEXT,
    fullName  TEXT,
    maxTime   BIGINT,
    maxMemory BIGINT
);
DROP TABLE t CASCADE;

DROP TABLE IF EXISTS attempts CASCADE;
CREATE TABLE IF NOT EXISTS attempts
(
    ID         BIGSERIAL NOT NULL PRIMARY KEY,
    userID     BIGINT    NOT NULL,
    taskID     BIGINT    NOT NULL,

    time       BIGINT,
    memory     BIGINT,

    sourceCode TEXT,
    uploadDate TIMESTAMP WITH TIME ZONE,

    FOREIGN KEY (userID) REFERENCES users (ID) ON DELETE CASCADE,
    FOREIGN KEY (taskID) REFERENCES tasks (ID) ON DELETE CASCADE
);

DROP TABLE IF EXISTS borrowings CASCADE;
CREATE TABLE IF NOT EXISTS borrowings
(
    attemptID         BIGINT NOT NULL,
    copiedFrom        BIGINT NOT NULL,
    plagiarismPercent INT,

    FOREIGN KEY (attemptID) REFERENCES attempts (ID) ON DELETE CASCADE,
    FOREIGN KEY (copiedFrom) REFERENCES attempts (ID) ON DELETE CASCADE
);

DROP TABLE IF EXISTS status CASCADE;
CREATE TABLE IF NOT EXISTS status
(
    attemptID BIGINT NOT NULL PRIMARY KEY,
    status    INT,

    FOREIGN KEY (attemptID) REFERENCES attempts (ID) ON DELETE CASCADE
);

DROP VIEW IF EXISTS results;
CREATE VIEW results
AS
SELECT u.userName          as userName,
       t.taskName          as taskName,
       a.uploadDate        as uploadDate,
       s.status            as status,
       b.plagiarismPercent as percent,
       u2.userName         as copiedFrom,
       t2.taskName         as copiedTask,
       a2.uploadDate       as copiedDate,
       a.sourcecode        as sourceCode,
       a2.sourceCode       as copiedCode
FROM users u
         JOIN attempts a on u.ID = a.userID
         JOIN tasks t ON a.taskID = t.ID
         JOIN borrowings b on a.ID = b.attemptID
         JOIN attempts a2 on b.copiedFrom = a2.ID
         JOIN users u2 ON a2.userID = u2.ID
         JOIN tasks t2 ON a2.taskID = t2.ID
         JOIN status s on a.ID = s.attemptID;