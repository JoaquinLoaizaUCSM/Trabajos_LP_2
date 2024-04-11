package Trabajo_4.actividad.repository;

import Trabajo_4.actividad.models.Comment;
import java.util.ArrayList;
import java.util.List;
import java.util.Optional;

public class CommentRepositoryImpl implements ICommentRepository{
    private List<Comment> comments = new ArrayList<>();

    @Override
    public void createComment(Comment comment) {
        comments.add(comment);
        System.out.println("Comment created: " + comment.getComment());
    }

    @Override
    public void deleteComment(Long id) {
        Optional<Comment> commentToRemove = comments.stream()
                .filter(comment -> comment.getId().equals(id))
                .findFirst();

        commentToRemove.ifPresent(comments::remove);
        System.out.println("Comment deleted with id: " + id);
    }

    @Override
    public void AdmitComment(Comment comment) {
//        System.out.println("Comment admitted: " + comment.getComment());
        System.out.println("Comment admitted: " + comment.getComment());
    }
}