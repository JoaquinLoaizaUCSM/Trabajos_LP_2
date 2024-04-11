package Trabajo_4.actividad.models;

public class Comment {
    private Long id;
    private String comment;
    private Date date;
    private Usuario user;

    public Comment(Long id, String comment, Date date, Usuario user) {
        this.id = id;
        this.comment = comment;
        this.date = date;
        this.user = user;
    }

    public Comment(String comment, Date date, Usuario user) {
        this.id = null;
        this.comment = comment;
        this.date = date;
        this.user = user;
    }

    public Comment() {
    }

    public Long getId() {
        return id;
    }

    public String getComment() {
        return comment;
    }

    public Date getDate() {
        return date;
    }

    public Usuario getUser() {
        return user;
    }

    public void setId(Long id) {
        this.id = id;
    }

    public void setComment(String comment) {
        this.comment = comment;
    }

    public void setDate(Date date) {
        this.date = date;
    }

    public void setUser(Usuario user) {
        this.user = user;
    }
}
