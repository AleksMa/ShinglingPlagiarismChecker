CREATE DATABASE docker;

create user docker with encrypted password 'docker';

grant all privileges on database docker to docker;

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

DROP TABLE IF EXISTS check_results CASCADE;
CREATE TABLE IF NOT EXISTS check_results
(
    attemptID         BIGINT NOT NULL,
    copiedFrom        BIGINT NOT NULL,
    plagiarismPercent INT,

    FOREIGN KEY (attemptID) REFERENCES attempts (ID) ON DELETE CASCADE,
    FOREIGN KEY (copiedFrom) REFERENCES users (ID) ON DELETE CASCADE
);

DROP TABLE IF EXISTS status CASCADE;
CREATE TABLE IF NOT EXISTS status
(
    attemptID BIGINT NOT NULL PRIMARY KEY,
    status    INT,

    FOREIGN KEY (attemptID) REFERENCES attempts (ID) ON DELETE CASCADE
);

CREATE VIEW checkResults
AS SELECT u.userName, tasks.taskName, a.uploadDate, s.status, cr.plagiarismPercent, u2.userName as copiedFrom FROM users u
                                                                                                                       JOIN attempts a on u.ID = a.userID
                                                                                                                       JOIN tasks ON a.taskID = tasks.ID
                                                                                                                       JOIN check_results cr on a.ID = cr.attemptID
                                                                                                                       JOIN attempts a2 on cr.copiedFrom = a2.ID
                                                                                                                       JOIN users u2 ON a2.userID = u2.ID
                                                                                                                       JOIN status s on a.ID = s.attemptID;



