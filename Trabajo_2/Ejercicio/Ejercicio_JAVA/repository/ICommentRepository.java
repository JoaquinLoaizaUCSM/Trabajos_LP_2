package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Comment;

public interface ICommentRepository {

    void createComment(Comment comment);

    void deleteComment(Long id);

    void AdmitComment(Comment comment);

}
